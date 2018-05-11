//
// Created by ruiy on 18-5-11.
//

#include "test.h"
#include "generate_file.h"
#include "io.h"
#include "compression.h"
#include "decompression.h"
#include <fstream>
#include <ctime>
#include <sys/time.h>

void test_compression(std::string relative_origin_basename, std::string relative_compression_res_basename, std::vector<int> range, std::string compression_filename_analysis) {
    generate(range, relative_origin_basename); // 生成若干源文件
    const char end_str = '$'; // 结束字符

    std::string time_cost = std::to_string(range[0]) + " " +
            std::to_string(range[1]) + " " +
            std::to_string(range[2]) + "\n"; // 记录每个文件的时间开销

    struct timeval start_timer, end_timer; // 用于计时

    for (int i=range[0];i<range[1];i+=range[2]) {
        gettimeofday(&start_timer, NULL);

        std::string origin = get_origin(relative_origin_basename + std::to_string(i));
        std::string compression_res = compression(origin);
        write_compression_res(compression_res, relative_compression_res_basename + std::to_string(i), end_str);

        gettimeofday(&end_timer, NULL);

        float sec_cost = end_timer.tv_sec - start_timer.tv_sec + (end_timer.tv_usec - start_timer.tv_usec) / 1000000.0;
        time_cost += std::to_string(sec_cost) + " ";
    }

    write_string(time_cost, compression_filename_analysis);
}

void test_decompression(std::string relative_compression_res_basename, std::string relative_decompression_res_basename, std::vector<int> range, std::string decompression_filename_analysis) {
    std::string time_cost = std::to_string(range[0]) + " " +
                            std::to_string(range[1]) + " " +
                            std::to_string(range[2]) + "\n"; // 记录每个文件的时间开销

    struct timeval start_timer, end_timer; // 用于计时

    for (int i=range[0];i<range[1];i+=range[2]) {
        gettimeofday(&start_timer, NULL);

        char end_str = get_end_str(relative_compression_res_basename + std::to_string(i));
        std::string compression_res = get_compression_res(relative_compression_res_basename + std::to_string(i));
        std::string decompression_res = decompression(compression_res, end_str);
        write_string(decompression_res, relative_decompression_res_basename + std::to_string(i));

        gettimeofday(&end_timer, NULL);
        float sec_cost = end_timer.tv_sec - start_timer.tv_sec + (end_timer.tv_usec - start_timer.tv_usec) / 1000000.0;
        time_cost += std::to_string(sec_cost) + " ";
    }

    write_string(time_cost, decompression_filename_analysis);
}