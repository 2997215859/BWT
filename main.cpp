//
// Created by ruiy on 18-5-8.
//

#include <cstdio>
#include <string>
#include <fstream>
#include <climits>

#include "compression.h"
#include "decompression.h"
#include "search.h"
#include "io.h"

/**
 *
 * @param args
 * @param argv 源文件路径 编码结果路径 解码结果路径 查询字符 查询结果路径
 * @return
 */
int main (int args, char *argv[]) {

    const char end_str = '$';

    std::string origin = get_origin(argv[1]);

    std::string compression_res = compression(origin);
    printf("compression res = %s\n", compression_res.c_str());
    write_compression_res(compression_res, argv[2], end_str);

    char test = get_end_str(argv[2]);

    std::string decompression_res = decompression(compression_res, end_str);
    printf("decompression res = %s\n", decompression_res.c_str());
    write_decompression_res(decompression_res, argv[3]);

    std::vector<int> offsets = search(compression_res, "and", end_str);
    printf("search count = %d\n", offsets.size());
}
