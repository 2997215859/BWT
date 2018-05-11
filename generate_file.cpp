//
// Created by ruiy on 18-5-11.
//

/**
 * 生成若干文件
 * @return
 */

#include <vector>
#include "generate_file.h"
#include "io.h"

void generate(std::vector<int> range, std::string relative_file_basename) {
     // 文件中字符个数从1到cnt
     if (range.size() != 3) {
         fprintf(stderr, "range参数应当为3");
         exit(1);
     }

     int start = range[0];
     int end = range[1];
     int step = range[2];

     for (int i=start;i<end;i+=step) {
         std::string origin("");
         for (int j=1;j<=i;j++) {
             int rnd = rand() % 26;
             char rand_char = 'a' + rnd;
             origin += rand_char;
         }
         write_string(origin, (relative_file_basename + std::to_string(i)).c_str());
     }
}