//
// Created by ruiy on 18-5-10.
//



#include "io.h"
#include <iostream>


/**
 * 从编码结果文件中取出压缩结果
 * @param relative_file_path
 * @return
 */
std::string get_compression_res(const std::string relative_file_path) {
    char file_path[PATH_MAX];
    realpath(relative_file_path.c_str(), file_path);
    std::ifstream read_handle(file_path);
    if (!read_handle.is_open()) {
        fprintf(stderr, "无法打开文件%s", file_path);
        exit(1);
    }

    read_handle.seekg(sizeof(int), std::ios::beg);
    std::string compression_res;
    while (!read_handle.eof()) {
        std::string line;
        getline(read_handle, line);
        compression_res += line;
    }
    return compression_res;
}

/**
 * 从编码结果文件中取出结束字符
 * @param relative_file_path
 * @return
 */
char get_end_str(const std::string relative_file_path) {
// 读入源文件
    char file_path[PATH_MAX];
    realpath(relative_file_path.c_str(), file_path);
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

/**
 * 从源文件中取出源字符串
 * @param relative_file_path
 * @return
 */
std::string get_origin (std::string relative_file_path) {
// 读入源文件
    char file_path[PATH_MAX];
    realpath(relative_file_path.c_str(), file_path);
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

/**
 * 将压缩结果写入文件
 * @param compression_res 压缩结果
 * @param relative_file_path 文件的相对路径
 * @param end_str 结束字符
 * @return
 */
int write_compression_res(std::string compression_res, std::string relative_file_path, char end_str) {

    int end_char_index = compression_res.find({end_str});

    char file_path[PATH_MAX];
    realpath(relative_file_path.c_str(), file_path);
    std::ofstream write_handle(file_path);
    if (!write_handle.is_open()) {
        fprintf(stderr, "无法打开文件%s", file_path);
        exit(1);
    }

    write_handle.write((char*)&end_char_index, sizeof(end_char_index));
    write_handle << compression_res;

    write_handle.close();
}

/**
 * 将字符串str写入文件
 * @param str
 * @param relative_file_path
 * @return
 */
int write_string(std::string str, std::string relative_file_path) {

    char file_path[PATH_MAX];
    realpath(relative_file_path.c_str(), file_path);
    std::ofstream write_handle(file_path);
    if (!write_handle.is_open()) {
        fprintf(stderr, "无法打开文件%s", file_path);
        exit(1);
    }

    write_handle << str;
    write_handle.close();
}
