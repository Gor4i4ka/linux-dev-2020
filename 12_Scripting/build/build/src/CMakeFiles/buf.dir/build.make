# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/cmake/715/bin/cmake

# The command to remove a file.
RM = /snap/cmake/715/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nick/linux-dev-2020/12_Scripting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/linux-dev-2020/12_Scripting/build

# Include any dependencies generated for this target.
include build/src/CMakeFiles/buf.dir/depend.make

# Include the progress variables for this target.
include build/src/CMakeFiles/buf.dir/progress.make

# Include the compile flags for this target's objects.
include build/src/CMakeFiles/buf.dir/flags.make

build/src/CMakeFiles/buf.dir/buf.c.o: build/src/CMakeFiles/buf.dir/flags.make
build/src/CMakeFiles/buf.dir/buf.c.o: ../src/buf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/linux-dev-2020/12_Scripting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object build/src/CMakeFiles/buf.dir/buf.c.o"
	cd /home/nick/linux-dev-2020/12_Scripting/build/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/buf.dir/buf.c.o -c /home/nick/linux-dev-2020/12_Scripting/src/buf.c

build/src/CMakeFiles/buf.dir/buf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/buf.dir/buf.c.i"
	cd /home/nick/linux-dev-2020/12_Scripting/build/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nick/linux-dev-2020/12_Scripting/src/buf.c > CMakeFiles/buf.dir/buf.c.i

build/src/CMakeFiles/buf.dir/buf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/buf.dir/buf.c.s"
	cd /home/nick/linux-dev-2020/12_Scripting/build/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nick/linux-dev-2020/12_Scripting/src/buf.c -o CMakeFiles/buf.dir/buf.c.s

# Object files for target buf
buf_OBJECTS = \
"CMakeFiles/buf.dir/buf.c.o"

# External object files for target buf
buf_EXTERNAL_OBJECTS =

lib/libbuf.a: build/src/CMakeFiles/buf.dir/buf.c.o
lib/libbuf.a: build/src/CMakeFiles/buf.dir/build.make
lib/libbuf.a: build/src/CMakeFiles/buf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nick/linux-dev-2020/12_Scripting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../lib/libbuf.a"
	cd /home/nick/linux-dev-2020/12_Scripting/build/build/src && $(CMAKE_COMMAND) -P CMakeFiles/buf.dir/cmake_clean_target.cmake
	cd /home/nick/linux-dev-2020/12_Scripting/build/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/buf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
build/src/CMakeFiles/buf.dir/build: lib/libbuf.a

.PHONY : build/src/CMakeFiles/buf.dir/build

build/src/CMakeFiles/buf.dir/clean:
	cd /home/nick/linux-dev-2020/12_Scripting/build/build/src && $(CMAKE_COMMAND) -P CMakeFiles/buf.dir/cmake_clean.cmake
.PHONY : build/src/CMakeFiles/buf.dir/clean

build/src/CMakeFiles/buf.dir/depend:
	cd /home/nick/linux-dev-2020/12_Scripting/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/linux-dev-2020/12_Scripting /home/nick/linux-dev-2020/12_Scripting/src /home/nick/linux-dev-2020/12_Scripting/build /home/nick/linux-dev-2020/12_Scripting/build/build/src /home/nick/linux-dev-2020/12_Scripting/build/build/src/CMakeFiles/buf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : build/src/CMakeFiles/buf.dir/depend
