//
// Created by ruiy on 18-5-8.
//

#include <algorithm>
#include "compression.h"
#include "decompression.h"

std::string compression(std::string origin, char end_str) {
    /**
     * example:
     * origin text: abaaba => abaaba$, 末尾添加$, 在该函数中, 为方便处理, 用''代替$
     * 然后计算 前缀数组, 实际效果相当于左移
     * suffix array is:
     *   前缀数组   缺的字符   末尾字符
     * 0 abaaba$             $
     * 1 baaba$     a        a
     * 2 aaba$     ab        b
     * 3 aba$     aba        a
     * 4 ba$     abaa        a
     * 5 a$     abaab        b
     * 6 $     abaaba        a
     *
     * 前缀数组按字母表排序, 然后根据排序后的前缀数组计算编码结果
     *
     * 编码结果：
     * 排序结果     末尾字符
     * $           a
     * a$          b
     * aaba$       b
     * aba$        a
     * abaaba$     $
     * ba$         a
     * baaba$      a
     *
     */
    std::vector<std::string> suffixs;
    for (int i=0;i<=origin.size();i++) suffixs.push_back(origin.substr(i));
    std::sort(suffixs.begin(), suffixs.end());

    std::string res;
    for (const std::string &suffix: suffixs) {
        if (suffix.size() == origin.size()) { // 此时, 末尾字符应该为$
            res.push_back(end_str);
            continue;
        }
        res.push_back(origin[suffix.size()]);
    }
    return res;
}

