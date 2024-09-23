cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_FLAGS "")
project(OI)

set(CMAKE_CXX_STANDARD 20)

add_executable(main nowcoder/main.cpp)

add_executable(e nowcoder/牛客周赛56/e.cpp)
add_executable(f nowcoder/牛客周赛57/f.cpp)
add_executable(c nowcoder/牛客周赛61/c.cpp)

add_executable(b nowcoder/牛客周赛61/b.cpp)
add_executable(k nowcoder/武汉理工程序设计大赛/k.cpp)

add_executable(d nowcoder/牛客周赛61/d.cpp)

add_executable(a nowcoder/牛客周赛61/a.cpp)

add_executable(g nowcoder/牛客周赛57/g.cpp)

add_executable(f2 nowcoder/牛客周赛56/f2.cpp)
add_executable(f3 nowcoder/牛客周赛56/f3.cpp)
add_executable(P1989 luogu/daily/P1989.cpp)
