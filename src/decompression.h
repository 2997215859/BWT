//
// Created by ruiy on 18-5-8.
//

#ifndef BWT_DECOMPRESSION_H
#define BWT_DECOMPRESSION_H

#include <string>
#include <vector>
#include <map>

/**
 *
 * @param bw 编码结果
 * @param end_str 结束字符, 不设默认值
 * @return
 */
std::string decompression (std::string bw, char end_str);

/**
 *
 * @param bw 编码结果
 * @param totals 记录各个字符的总数
 * @param ranks 记录之前出现相同字符的个数
 */
inline void calc_ranks(const std::string &bw, std::map<char, int> &totals, std::vector<int> &ranks){
    for (const char &t: bw) ranks.push_back(totals[t]++);
}

/**
 * 记录各个字符在第一列的起始索引和终止索引（左闭右开）
 * @param totals 各个字符的总数
 * @return
 */
std::map<char, std::pair<int, int>> get_first_col_index(const std::map<char, int> &totals, char end_str);

#endif //BWT_DECOMPRESSION_H


