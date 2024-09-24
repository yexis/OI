cmake_minimum_required(VERSION 3.17)
project(OI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OSX_SYSROOT /Library/Developer/CommandLineTools/SDKs/MacOSX14.sdk)

add_executable(b nowcoder/牛客周赛61/b.cpp)
add_executable(main nowcoder/main.cpp)
add_executable(a nowcoder/牛客周赛61/a.cpp)