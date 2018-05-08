//
// Created by ruiy on 18-5-8.
//

#include "search.h"
#include "decompression.h"


std::vector<int> search (std::string bw, std::string p, char end_str) {
    std::map<char, int> totals; // 记录各个字符的总数
    std::vector<int> ranks; // 记录之前出现相同字符的个数
    calc_ranks(bw, totals, ranks);

    std::map<char, std::pair<int, int>> range_index = get_first_col_index(totals, end_str);
    // p最后一个字符的起始和终止
    int start = range_index[p.back()].first;
    int end = range_index[p.back()].second;

    /**
     * 回溯查询比对得到下一个字符的范围
     */
    int i = p.size() - 2;
    while (i >= 0 && start < end) {
        char c = p[i];
        int j = start;
        while (j < end) {
            if (bw[j] == c) {
                start = range_index[c].first + ranks[j];
                break;
            }
            j++;
        }

        if (j == end) { // 一个都没有查到
            start = end;
            break;
        }

        end--;
        while (bw[end] != c) {
            end--;
        }
        end = range_index[c].first + ranks[end] + 1;
        i--;
    } // 返回第一列中p的第一个字符的索引范围 [start, end)

    // 计算offset
    std::vector<int> offsets;
    for (int i=start;i<end;i++) {
        int offset = 0;
        int row = i;
        while (bw[row] != end_str) {
            offset++;
            row = range_index[bw[row]].first + ranks[row];
        }
        offsets.push_back(offset);
    }

    return offsets;
}