//
// Created by ruiy on 18-5-8.
//

#ifndef BWT_COMPRESSION_H
#define BWT_COMPRESSION_H

#include <string>
#include <vector>

/**
 * 用bwt编码origin
 * @param origin 原始文本
 * @param end_str 结束字符, 默认'$'
 * @return 编码结果
 */
std::string compression(std::string origin, char end_str = '$');

/**
 * 计算origin的前缀数组
 * @param origin 原字符串(不包含结束字符$)
 * @return
 */
std::vector<std::string> calc_suffix_array(std::string origin);

#endif //BWT_COMPRESSION_H
