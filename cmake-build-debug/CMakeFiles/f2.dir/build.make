# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yex/CPP/OI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yex/CPP/OI/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/f2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/f2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/f2.dir/flags.make

CMakeFiles/f2.dir/nowcoder/牛客周赛56/f2.cpp.o: CMakeFiles/f2.dir/flags.make
CMakeFiles/f2.dir/nowcoder/牛客周赛56/f2.cpp.o: ../nowcoder/牛客周赛56/f2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yex/CPP/OI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/f2.dir/nowcoder/牛客周赛56/f2.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/f2.dir/nowcoder/牛客周赛56/f2.cpp.o -c /Users/yex/CPP/OI/nowcoder/牛客周赛56/f2.cpp

CMakeFiles/f2.dir/nowcoder/牛客周赛56/f2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/f2.dir/nowcoder/牛客周赛56/f2.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yex/CPP/OI/nowcoder/牛客周赛56/f2.cpp > CMakeFiles/f2.dir/nowcoder/牛客周赛56/f2.cpp.i

CMakeFiles/f2.dir/nowcoder/牛客周赛56/f2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/f2.dir/nowcoder/牛客周赛56/f2.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yex/CPP/OI/nowcoder/牛客周赛56/f2.cpp -o CMakeFiles/f2.dir/nowcoder/牛客周赛56/f2.cpp.s

# Object files for target f2
f2_OBJECTS = \
"CMakeFiles/f2.dir/nowcoder/牛客周赛56/f2.cpp.o"

# External object files for target f2
f2_EXTERNAL_OBJECTS =

f2: CMakeFiles/f2.dir/nowcoder/牛客周赛56/f2.cpp.o
f2: CMakeFiles/f2.dir/build.make
f2: CMakeFiles/f2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yex/CPP/OI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable f2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/f2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/f2.dir/build: f2

.PHONY : CMakeFiles/f2.dir/build

CMakeFiles/f2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/f2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/f2.dir/clean

CMakeFiles/f2.dir/depend:
	cd /Users/yex/CPP/OI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yex/CPP/OI /Users/yex/CPP/OI /Users/yex/CPP/OI/cmake-build-debug /Users/yex/CPP/OI/cmake-build-debug /Users/yex/CPP/OI/cmake-build-debug/CMakeFiles/f2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/f2.dir/depend
