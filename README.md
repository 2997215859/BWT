# BWT
compression, decompression and search for algorithom Burrows-Wheeler Transform(BWT)
实现BWT的编码, 解码, 查找

## 文件说明

```
.
├── bin
│   └── bwt                           # 编译结果, 可执行文件
├── CMakeLists.txt
├── data                              # 存放各种文本数据
│   ├── analysis
│   │   ├── case_compression_time     # 各个文件编码所需时间, 时间单位为微秒
│   │   └── case_decompression_time   # 各个文件解码所需时间, 时间单位为微秒
│   ├── compression                   # 存放压缩结果, case12就表示该文件中字符串长度为12
│   │   ├── case12
│   │   ├── case15
│   │   ├── case18
│   │   ├── case3
│   │   ├── case6
│   │   └── case9
│   ├── decompression                 # 同上，类似
│   │   └── ... 
│   └── origin                        # 同上, 类似
│       └── ... 
└── src                               # 代码
    ├── compression.cpp               # 编码算法
    ├── compression.h
    ├── decompression.cpp             # 解码算法
    ├── decompression.h
    ├── generate_file.cpp             # 自动生成文件
    ├── generate_file.h                
    ├── io.cpp                        # 处理文本IO
    ├── io.h
    ├── main.cpp                      
    ├── search.cpp                    # 查找算法
    ├── search.h                     
    ├── test.cpp                      # 测试
    └── test.h
```

## 注
1. 数据目录需要自己建立, 代码中未提供新建目录的功能, 同样, 不提供清空目录的功能...
2. 最好还是将编码、解码、查找分别编译成二进制文件， 然后使用脚本测试最好, 这里不想写了...凑合用
3. 时间复杂度，相关数据写在case_compression_time和case_decompression_time文件中，格式为两行

   * 第一行, 三个整数, 比如 3, 18, 3, 则表示所测试的各个文本长度是从3开始, 步长为3, 一直到18(不包括)结束 
   * 第二行，各个文本对应所用时间, 时间单位为微秒
   
4. 测试文本是利用generate_file.cpp生成, **如果想要生成不同间距, 起始位置的文本**, 只需要在`main.cpp`中更改传入的实参range即可

## 环境
linux ubuntu 16.04
