//
// Created by ruiy on 18-5-8.
//

#include <cstdio>
#include <string>
#include "compression.h"
#include "decompression.h"
#include "search.h"

int main () {
//    std::string origin("abaaba");
    std::string origin("Tomorrow and tomorrow and tomorrow and tomorrow");
//    std::string origin("Tomorrow and tomorrow");
    std::string compression_res = compression(origin);
    printf("compression res = %s\n", compression_res.c_str());

    std::string decompression_res = decompression(compression_res, '$');
    printf("decompression res = %s\n", decompression_res.c_str());

    int count = search(compression_res, "and", '$');
    printf("search count = %d\n", count);
}