//
// Created by ruiy on 18-5-8.
//

#include "search.h"
#include "decompression.h"

int search (std::string bw, std::string p) {
    std::map<char, int> totals; // 记录各个字符的总数
    std::vector<int> ranks; // 记录之前出现相同字符的个数
    calc_ranks(bw, totals, ranks);

    std::map<char, std::pair<int, int>> range_index = get_first_col_index(totals);
    // p最后一个字符的起始和终止
    int start = range_index[p.back()].first;
    int end = range_index[p.back()].second;

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

        if (j == end) {
            start = end;
            break;
        }

        end--;
        while (bw[end] != c) {
            end--;
        }
        end = range_index[c].first + ranks[end] + 1;
        i--;
    }
    return end - start;
}