cmake_minimum_required(VERSION 3.17)
project(OI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OSX_SYSROOT /Library/Developer/CommandLineTools/SDKs/MacOSX14.sdk)

add_executable(b nowcoder/牛客周赛61/b.cpp)
add_executable(main nowcoder/main.cpp)
add_executable(a nowcoder/norank/香港城市大学（东莞）2024新生排位赛/a.cpp)
add_executable(c nowcoder/牛客周赛63/c.cpp)
add_executable(g nowcoder/牛客周赛62/g.cpp)
add_executable(h nowcoder/norank/香港城市大学（东莞）2024新生排位赛/h.cpp)
add_executable(e nowcoder/牛客周赛63/e.cpp)
add_executable(d nowcoder/norank/香港城市大学（东莞）2024新生排位赛/d.cpp)

add_executable(f nowcoder/牛客周赛62/f1_static.cpp)

add_executable(f3_dynamic nowcoder/牛客周赛62/f3_dynamic.cpp)
add_executable(f3_dynamic_luogu nowcoder/牛客周赛62/f3_dynamic_luogu.cpp)