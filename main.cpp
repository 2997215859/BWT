//
// Created by ruiy on 18-5-8.
//

#include <cstdio>
#include <string>
#include "compression.h"
#include "decompression.h"
#include "search.h"

int main () {
    const char end_str = '$';

//    std::string origin("abaaba");
    std::string origin("stl cpp primer and effective cpp and modern effective cpp and effective stl");

    std::string compression_res = compression(origin);
    printf("compression res = %s\n", compression_res.c_str());

    std::string decompression_res = decompression(compression_res, end_str);
    printf("decompression res = %s\n", decompression_res.c_str());

    std::vector<int> offsets = search(compression_res, "and", end_str);
    printf("search count = %d\n", offsets.size());
}
