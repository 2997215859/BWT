//
// Created by ruiy on 18-5-10.
//

#ifndef BWT_IO_H
#define BWT_IO_H

#include <climits>
#include <stdlib.h>
#include <fstream>

char get_end_str(const char* relative_file_path);
std::string get_origin (const char* relative_file_path);
int write_compression_res(std::string compression_res, const char* relative_file_path, char end_str);
int write_decompression_res(std::string decompression_res, const char* relative_file_path);

#endif //BWT_IO_H
