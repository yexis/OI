#!/bin/bash

# 检查是否传入了文件名参数
if [ $# -eq 0 ]; then
    echo "使用方法: $0 <文件名>"
    exit 1
fi

# 获取文件名参数
FILE_NAME="$1.cpp"

# 检查文件是否存在
if [ ! -f "$FILE_NAME" ]; then
    echo "错误: 文件 $FILE_NAME 不存在"
    exit 2
fi

# 编译并运行
clang++ -std=c++20 "$FILE_NAME" -o t
if [ $? -ne 0 ]; then
    echo "编译失败"
    exit 3
fi

# 运行生成的可执行文件
./t
EXIT_CODE=$?

# 打印运行结果的退出码
echo "exit: $EXIT_CODE"
exit $EXIT_CODE