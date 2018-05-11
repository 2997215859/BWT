//
// Created by ruiy on 18-5-11.
//

/**
 * 生成若干文件
 * @return
 */

#include "generate_file.h"
#include "io.h"

void generate(int cnt, std::string relative_file_basename) {
     // 文件中字符个数从1到cnt
     for (int i=0;i<cnt;i++) {
         std::string origin("");
         for (int j=0;j<=i;j++) {
             int rnd = rand() % 26;
             char rand_char = 'a' + rnd;
             origin += rand_char;
         }
         write_string(origin, (relative_file_basename + std::to_string(i)).c_str());
     }
}