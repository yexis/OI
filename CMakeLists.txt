cmake_minimum_required(VERSION 3.17)
project(OI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OSX_SYSROOT /Library/Developer/CommandLineTools/SDKs/MacOSX14.sdk)

add_executable(b nowcoder/牛客周赛61/b.cpp)
add_executable(main nowcoder/main.cpp)
add_executable(a nowcoder/norank/香港城市大学（东莞）2024新生排位赛/a.cpp)
add_executable(c nowcoder/norank/香港城市大学（东莞）2024新生排位赛/c.cpp)
add_executable(g nowcoder/norank/香港城市大学（东莞）2024新生排位赛/g.cpp)
add_executable(h nowcoder/norank/香港城市大学（东莞）2024新生排位赛/h.cpp)
add_executable(e nowcoder/norank/香港城市大学（东莞）2024新生排位赛/e.cpp)
add_executable(d nowcoder/norank/香港城市大学（东莞）2024新生排位赛/d.cpp)
