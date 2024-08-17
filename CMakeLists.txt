cmake_minimum_required(VERSION 3.17)
project(OI)

set(CMAKE_CXX_STANDARD 20)

add_executable(main nowcoder/main.cpp)

add_executable(e nowcoder/牛客周赛55/e.cpp)
add_executable(f nowcoder/牛客周赛53/f.cpp)
add_executable(c "luogu/梦熊周赛 提高组2/c.cpp")

add_executable(b "luogu/梦熊周赛 提高组2/b.cpp")
add_executable(k nowcoder/武汉理工程序设计大赛/k.cpp)

add_executable(d nowcoder/牛客周赛55/d.cpp)

add_executable(a "luogu/熊梦周赛 S3/a.cpp")

add_executable(g nowcoder/牛客周赛53/g.cpp)
