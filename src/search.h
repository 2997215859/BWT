//
// Created by ruiy on 18-5-8.
//

#ifndef BWT_SEARCH_H
#define BWT_SEARCH_H

#include <string>
#include <vector>
#include <algorithm>


/**
 * 返回第一列中p的第一个字符的索引范围
 * @param bw 编码结果
 * @param p 要查找的字符串
 * @param end_str 结束字符
 * @return
 */
std::vector<int> search (std::string bw, std::string p, char end_str);

#endif //BWT_SEARCH_H
