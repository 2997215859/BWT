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
#include "test.h"

/**
 *
 * @param args
 * @param argv
 * @return
 */

int main (int args, char *argv[]) {
    std::string relative_origin_basename = "../data/origin/case";
    std::string relative_compression_res_basename = "../data/compression/case";
    std::string relative_decompressio_res_basename = "../data/decompression/case";

    std::string compression_filename_analysis = "../data/analysis/case_compression_time";
    std::string decompression_filename_analysis = "../data/analysis/case_decompression_time";

    std::vector<int> range = {3, 300, 3}; // 左闭右开, 左3, 右300, 步距为3
    test_compression(relative_origin_basename, relative_compression_res_basename, range, compression_filename_analysis);
    test_decompression(relative_compression_res_basename, relative_decompressio_res_basename, range, decompression_filename_analysis);

//    std::vector<int> offsets = search(compression_res, "and", end_str);
//    printf("search count = %d\n", offsets.size());
}
