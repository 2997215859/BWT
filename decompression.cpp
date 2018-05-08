//
// Created by ruiy on 18-5-8.
//

#include "decompression.h"

std::map<char, std::pair<int, int>> get_first_col_index(const std::map<char, int> &totals){
    std::map<char, std::pair<int, int>> start_index;
    int cnt = 0;
    for (auto &t: totals) {
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
    std::map<char, std::pair<int, int>> range_index = get_first_col_index(totals);

    // 回溯
    int row = 0;
    std::string res("$");
    while (bw[row] != end_str) {
        res = bw[row] + res;
        row = range_index[bw[row]].first + ranks[row];
    }
    return res;
}