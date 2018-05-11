//
// Created by ruiy on 18-5-11.
//

#ifndef BWT_TEST_COMPRESSION_H
#define BWT_TEST_COMPRESSION_H

#include <string>
#include <vector>

void test_compression(std::string relative_origin_basename, std::string relative_compression_res_basename, std::vector<int> range, std::string compression_filename_analysis);
void test_decompression(std::string relative_compression_res_basename, std::string relative_decompression_res_basename, std::vector<int> range, std::string decompression_filename_analysis);
#endif //BWT_TEST_COMPRESSION_H
