# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /private/var/folders/5l/g1htggqd3pj0rl5r6km0w8y40000gn/T/AppTranslocation/CAEF89C1-6A3A-42CF-9D7C-288978005C3B/d/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /private/var/folders/5l/g1htggqd3pj0rl5r6km0w8y40000gn/T/AppTranslocation/CAEF89C1-6A3A-42CF-9D7C-288978005C3B/d/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrejaksenov/CLionProjects/image_processor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrejaksenov/CLionProjects/image_processor/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/image_processor.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/image_processor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image_processor.dir/flags.make

CMakeFiles/image_processor.dir/image_processor.cpp.o: CMakeFiles/image_processor.dir/flags.make
CMakeFiles/image_processor.dir/image_processor.cpp.o: ../image_processor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrejaksenov/CLionProjects/image_processor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image_processor.dir/image_processor.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image_processor.dir/image_processor.cpp.o -c /Users/andrejaksenov/CLionProjects/image_processor/image_processor.cpp

CMakeFiles/image_processor.dir/image_processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_processor.dir/image_processor.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrejaksenov/CLionProjects/image_processor/image_processor.cpp > CMakeFiles/image_processor.dir/image_processor.cpp.i

CMakeFiles/image_processor.dir/image_processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_processor.dir/image_processor.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrejaksenov/CLionProjects/image_processor/image_processor.cpp -o CMakeFiles/image_processor.dir/image_processor.cpp.s

CMakeFiles/image_processor.dir/bitmap.cpp.o: CMakeFiles/image_processor.dir/flags.make
CMakeFiles/image_processor.dir/bitmap.cpp.o: ../bitmap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrejaksenov/CLionProjects/image_processor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/image_processor.dir/bitmap.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image_processor.dir/bitmap.cpp.o -c /Users/andrejaksenov/CLionProjects/image_processor/bitmap.cpp

CMakeFiles/image_processor.dir/bitmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_processor.dir/bitmap.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrejaksenov/CLionProjects/image_processor/bitmap.cpp > CMakeFiles/image_processor.dir/bitmap.cpp.i

CMakeFiles/image_processor.dir/bitmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_processor.dir/bitmap.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrejaksenov/CLionProjects/image_processor/bitmap.cpp -o CMakeFiles/image_processor.dir/bitmap.cpp.s

CMakeFiles/image_processor.dir/parser.cpp.o: CMakeFiles/image_processor.dir/flags.make
CMakeFiles/image_processor.dir/parser.cpp.o: ../parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrejaksenov/CLionProjects/image_processor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/image_processor.dir/parser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image_processor.dir/parser.cpp.o -c /Users/andrejaksenov/CLionProjects/image_processor/parser.cpp

CMakeFiles/image_processor.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_processor.dir/parser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrejaksenov/CLionProjects/image_processor/parser.cpp > CMakeFiles/image_processor.dir/parser.cpp.i

CMakeFiles/image_processor.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_processor.dir/parser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrejaksenov/CLionProjects/image_processor/parser.cpp -o CMakeFiles/image_processor.dir/parser.cpp.s

CMakeFiles/image_processor.dir/filters.cpp.o: CMakeFiles/image_processor.dir/flags.make
CMakeFiles/image_processor.dir/filters.cpp.o: ../filters.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrejaksenov/CLionProjects/image_processor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/image_processor.dir/filters.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image_processor.dir/filters.cpp.o -c /Users/andrejaksenov/CLionProjects/image_processor/filters.cpp

CMakeFiles/image_processor.dir/filters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_processor.dir/filters.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrejaksenov/CLionProjects/image_processor/filters.cpp > CMakeFiles/image_processor.dir/filters.cpp.i

CMakeFiles/image_processor.dir/filters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_processor.dir/filters.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrejaksenov/CLionProjects/image_processor/filters.cpp -o CMakeFiles/image_processor.dir/filters.cpp.s

CMakeFiles/image_processor.dir/filter_apply.cpp.o: CMakeFiles/image_processor.dir/flags.make
CMakeFiles/image_processor.dir/filter_apply.cpp.o: ../filter_apply.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrejaksenov/CLionProjects/image_processor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/image_processor.dir/filter_apply.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/image_processor.dir/filter_apply.cpp.o -c /Users/andrejaksenov/CLionProjects/image_processor/filter_apply.cpp

CMakeFiles/image_processor.dir/filter_apply.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_processor.dir/filter_apply.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrejaksenov/CLionProjects/image_processor/filter_apply.cpp > CMakeFiles/image_processor.dir/filter_apply.cpp.i

CMakeFiles/image_processor.dir/filter_apply.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_processor.dir/filter_apply.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrejaksenov/CLionProjects/image_processor/filter_apply.cpp -o CMakeFiles/image_processor.dir/filter_apply.cpp.s

# Object files for target image_processor
image_processor_OBJECTS = \
"CMakeFiles/image_processor.dir/image_processor.cpp.o" \
"CMakeFiles/image_processor.dir/bitmap.cpp.o" \
"CMakeFiles/image_processor.dir/parser.cpp.o" \
"CMakeFiles/image_processor.dir/filters.cpp.o" \
"CMakeFiles/image_processor.dir/filter_apply.cpp.o"

# External object files for target image_processor
image_processor_EXTERNAL_OBJECTS =

image_processor: CMakeFiles/image_processor.dir/image_processor.cpp.o
image_processor: CMakeFiles/image_processor.dir/bitmap.cpp.o
image_processor: CMakeFiles/image_processor.dir/parser.cpp.o
image_processor: CMakeFiles/image_processor.dir/filters.cpp.o
image_processor: CMakeFiles/image_processor.dir/filter_apply.cpp.o
image_processor: CMakeFiles/image_processor.dir/build.make
image_processor: CMakeFiles/image_processor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andrejaksenov/CLionProjects/image_processor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable image_processor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image_processor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image_processor.dir/build: image_processor
.PHONY : CMakeFiles/image_processor.dir/build

CMakeFiles/image_processor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image_processor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image_processor.dir/clean

CMakeFiles/image_processor.dir/depend:
	cd /Users/andrejaksenov/CLionProjects/image_processor/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrejaksenov/CLionProjects/image_processor /Users/andrejaksenov/CLionProjects/image_processor /Users/andrejaksenov/CLionProjects/image_processor/cmake-build-debug /Users/andrejaksenov/CLionProjects/image_processor/cmake-build-debug /Users/andrejaksenov/CLionProjects/image_processor/cmake-build-debug/CMakeFiles/image_processor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/image_processor.dir/depend
