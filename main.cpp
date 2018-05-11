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
#include "generate_file.h"

/**
 *
 * @param args
 * @param argv 源文件路径 编码结果路径 解码结果路径 查询字符 查询结果路径
 * @return
 */
int main (int args, char *argv[]) {

    int file_num = 2;
    std::string relative_origin_basename = "../data/origin/case";
    generate(2, relative_origin_basename);

    std::string relative_compression_res_basename = "../data/compression/case";
    std::string relative_decompression_res_basename = "../data/decompression/case";

    const char end_str = '$';
    for (int i=0;i<file_num;i++) {
        std::string origin = get_origin(relative_origin_basename + std::to_string(i));
        std::string compression_res = compression(origin);
        write_compression_res(compression_res, relative_compression_res_basename + std::to_string(i), end_str);
    }

    for (int i=0;i<file_num;i++) {
        char t = get_end_str(relative_compression_res_basename + std::to_string(i));
        std::string compression_res = get_compression_res(relative_compression_res_basename + std::to_string(i));
        std::string decompression_res = decompression(compression_res, end_str);
        write_string(decompression_res, relative_decompression_res_basename + std::to_string(i));
    }
    
//    std::vector<int> offsets = search(compression_res, "and", end_str);
//    printf("search count = %d\n", offsets.size());
}
