# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nick/linux-dev-2020/09_I18nL10n

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/linux-dev-2020/09_I18nL10n/build

# Utility rule file for update_po.

# Include the progress variables for this target.
include CMakeFiles/update_po.dir/progress.make

CMakeFiles/update_po: update


update:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nick/linux-dev-2020/09_I18nL10n/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating update"
	xgettext --keyword=_ --language=C --add-comments --sort-output -o /home/nick/linux-dev-2020/09_I18nL10n/po/task9.pot /home/nick/linux-dev-2020/09_I18nL10n/src/task9.c
	msgmerge --update /home/nick/linux-dev-2020/09_I18nL10n/po/ru/task9.po /home/nick/linux-dev-2020/09_I18nL10n/po/task9.pot
	msgmerge --update /home/nick/linux-dev-2020/09_I18nL10n/po/en/task9.po /home/nick/linux-dev-2020/09_I18nL10n/po/task9.pot

update_po: CMakeFiles/update_po
update_po: update
update_po: CMakeFiles/update_po.dir/build.make

.PHONY : update_po

# Rule to build all files generated by this target.
CMakeFiles/update_po.dir/build: update_po

.PHONY : CMakeFiles/update_po.dir/build

CMakeFiles/update_po.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/update_po.dir/cmake_clean.cmake
.PHONY : CMakeFiles/update_po.dir/clean

CMakeFiles/update_po.dir/depend:
	cd /home/nick/linux-dev-2020/09_I18nL10n/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/linux-dev-2020/09_I18nL10n /home/nick/linux-dev-2020/09_I18nL10n /home/nick/linux-dev-2020/09_I18nL10n/build /home/nick/linux-dev-2020/09_I18nL10n/build /home/nick/linux-dev-2020/09_I18nL10n/build/CMakeFiles/update_po.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/update_po.dir/depend

