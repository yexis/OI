cmake_minimum_required(VERSION 3.17)
project(OI)

set(CMAKE_CXX_STANDARD 14)

add_executable(main nowcoder/main.cpp)

add_executable(e nowcoder/武汉理工程序设计大赛/e.cpp)
add_executable(f nowcoder/牛客小白月赛97/f.cpp)
add_executable(c nowcoder/牛客练习赛127/c.cpp)

add_executable(b nowcoder/牛客练习赛127/b.cpp)
add_executable(h nowcoder/武汉理工程序设计大赛/h.cpp)
add_executable(k nowcoder/武汉理工程序设计大赛/k.cpp)

add_executable(d nowcoder/牛客周赛50/d.cpp)