//
// Created by ruiy on 18-5-10.
//



#include "io.h"
#include <iostream>

char get_end_str(const char* relative_file_path) {
// 读入源文件
    char file_path[PATH_MAX];
    realpath(relative_file_path, file_path);
    std::ifstream read_handle(file_path);
    if (!read_handle.is_open()) {
        fprintf(stderr, "无法打开文件%s", file_path);
        exit(1);
    }

    int end_str_index;
    read_handle.read((char*)&end_str_index, sizeof(end_str_index));
    read_handle.seekg(end_str_index, std::ios::cur);
    char end_str = read_handle.get();
    read_handle.close();

    return end_str;
}

std::string get_origin (const char* relative_file_path) {
// 读入源文件
    char file_path[PATH_MAX];
    realpath(relative_file_path, file_path);
    std::ifstream read_handle(file_path);
    if (!read_handle.is_open()) {
        fprintf(stderr, "无法打开文件%s", file_path);
        exit(1);
    }
    std::string origin;
    std::string line;
    while (getline(read_handle, line)) origin += line;

    read_handle.close();
    return origin;
}

int write_compression_res(std::string compression_res, const char* relative_file_path, char end_str) {

    int end_char_index = compression_res.find({end_str});

    char file_path[PATH_MAX];
    realpath(relative_file_path, file_path);
    std::ofstream write_handle(file_path);
    if (!write_handle.is_open()) {
        fprintf(stderr, "无法打开文件%s", file_path);
        exit(1);
    }

    write_handle.write((char*)&end_char_index, sizeof(end_char_index));
    write_handle << compression_res;

    write_handle.close();
}

int write_decompression_res(std::string decompression_res, const char* relative_file_path) {

    char file_path[PATH_MAX];
    realpath(relative_file_path, file_path);
    std::ofstream write_handle(file_path);
    if (!write_handle.is_open()) {
        fprintf(stderr, "无法打开文件%s", file_path);
        exit(1);
    }

    write_handle << decompression_res;
    write_handle.close();
}
