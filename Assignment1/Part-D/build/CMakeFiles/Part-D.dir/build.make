# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D/build

# Include any dependencies generated for this target.
include CMakeFiles/Part-D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Part-D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Part-D.dir/flags.make

CMakeFiles/Part-D.dir/simple.cpp.o: CMakeFiles/Part-D.dir/flags.make
CMakeFiles/Part-D.dir/simple.cpp.o: ../simple.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Part-D.dir/simple.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Part-D.dir/simple.cpp.o -c /Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D/simple.cpp

CMakeFiles/Part-D.dir/simple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part-D.dir/simple.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D/simple.cpp > CMakeFiles/Part-D.dir/simple.cpp.i

CMakeFiles/Part-D.dir/simple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part-D.dir/simple.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D/simple.cpp -o CMakeFiles/Part-D.dir/simple.cpp.s

# Object files for target Part-D
Part__D_OBJECTS = \
"CMakeFiles/Part-D.dir/simple.cpp.o"

# External object files for target Part-D
Part__D_EXTERNAL_OBJECTS =

Part-D: CMakeFiles/Part-D.dir/simple.cpp.o
Part-D: CMakeFiles/Part-D.dir/build.make
Part-D: /usr/local/Cellar/glew/2.1.0_1/lib/libGLEW.2.1.0.dylib
Part-D: /usr/local/Cellar/glfw/3.3.2/lib/libglfw.3.3.dylib
Part-D: CMakeFiles/Part-D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Part-D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Part-D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Part-D.dir/build: Part-D

.PHONY : CMakeFiles/Part-D.dir/build

CMakeFiles/Part-D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Part-D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Part-D.dir/clean

CMakeFiles/Part-D.dir/depend:
	cd /Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D /Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D /Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D/build /Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D/build /Users/felipecosta/Desktop/CS4610/github/Assignment1/Part-D/build/CMakeFiles/Part-D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Part-D.dir/depend

