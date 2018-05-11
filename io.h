//
// Created by ruiy on 18-5-10.
//

#ifndef BWT_IO_H
#define BWT_IO_H

#include <climits>
#include <stdlib.h>
#include <fstream>


int write_compression_res(std::string compression_res, std::string relative_file_path, char end_str);
int write_string(std::string decompression_res, std::string relative_file_path);

std::string get_origin (std::string relative_file_path);
char get_end_str(const std::string relative_file_path);
std::string get_compression_res(const std::string relative_file_path);
#endif //BWT_IO_H
