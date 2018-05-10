//
// Created by ruiy on 18-5-8.
//

#include <algorithm>
#include "decompression.h"

std::map<char, std::pair<int, int>> get_first_col_index(const std::map<char, int> &totals, char end_str){
    std::map<char, std::pair<int, int>> start_index;

    std::vector<std::pair<char, int>> sort_totals(totals.begin(), totals.end());
    std::sort(sort_totals.begin(), sort_totals.end(), [end_str](const std::pair<char, int> &o1, const std::pair<char, int>& o2){
        if (o1.first == end_str) {
            return true;
        } else if (o2.first == end_str) {
            return false;
        }
        return o1.first < o2.first;
    });
    int cnt = 0;
    for (auto &t: sort_totals) {
        start_index[t.first] = {cnt, cnt + totals.at(t.first)};
        cnt += totals.at(t.first);
    }
    return start_index;
}

std::string decompression (std::string bw, char end_str) {

    /**
     * F L rank
     * $ a 0
     * a b 0
     * a b 1
     * a a 1
     * a $ 0
     * b a 2
     * b a 3
     */

    std::map<char, int> totals; // 记录各个字符的总数
    std::vector<int> ranks; // 记录之前出现相同字符的个数
    calc_ranks(bw, totals, ranks);

    // 记录各个字符在第一列的起始索引和终止索引
    std::map<char, std::pair<int, int>> range_index = get_first_col_index(totals, end_str);

    // 回溯
    int row = 0;
    std::string res({end_str});
    while (bw[row] != end_str) {
        char c = bw[row];
        res = c + res;
        row = range_index[bw[row]].first + ranks[row];
    }
    return res;
}