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
CMAKE_SOURCE_DIR = /home/mirmik/project/servoce

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mirmik/project/servoce

# Include any dependencies generated for this target.
include CMakeFiles/servoce_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/servoce_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/servoce_test.dir/flags.make

CMakeFiles/servoce_test.dir/utests/curve3.cpp.o: CMakeFiles/servoce_test.dir/flags.make
CMakeFiles/servoce_test.dir/utests/curve3.cpp.o: utests/curve3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mirmik/project/servoce/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/servoce_test.dir/utests/curve3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servoce_test.dir/utests/curve3.cpp.o -c /home/mirmik/project/servoce/utests/curve3.cpp

CMakeFiles/servoce_test.dir/utests/curve3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servoce_test.dir/utests/curve3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mirmik/project/servoce/utests/curve3.cpp > CMakeFiles/servoce_test.dir/utests/curve3.cpp.i

CMakeFiles/servoce_test.dir/utests/curve3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servoce_test.dir/utests/curve3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mirmik/project/servoce/utests/curve3.cpp -o CMakeFiles/servoce_test.dir/utests/curve3.cpp.s

CMakeFiles/servoce_test.dir/utests/curve3.cpp.o.requires:

.PHONY : CMakeFiles/servoce_test.dir/utests/curve3.cpp.o.requires

CMakeFiles/servoce_test.dir/utests/curve3.cpp.o.provides: CMakeFiles/servoce_test.dir/utests/curve3.cpp.o.requires
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/curve3.cpp.o.provides.build
.PHONY : CMakeFiles/servoce_test.dir/utests/curve3.cpp.o.provides

CMakeFiles/servoce_test.dir/utests/curve3.cpp.o.provides.build: CMakeFiles/servoce_test.dir/utests/curve3.cpp.o


CMakeFiles/servoce_test.dir/utests/face.cpp.o: CMakeFiles/servoce_test.dir/flags.make
CMakeFiles/servoce_test.dir/utests/face.cpp.o: utests/face.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mirmik/project/servoce/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/servoce_test.dir/utests/face.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servoce_test.dir/utests/face.cpp.o -c /home/mirmik/project/servoce/utests/face.cpp

CMakeFiles/servoce_test.dir/utests/face.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servoce_test.dir/utests/face.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mirmik/project/servoce/utests/face.cpp > CMakeFiles/servoce_test.dir/utests/face.cpp.i

CMakeFiles/servoce_test.dir/utests/face.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servoce_test.dir/utests/face.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mirmik/project/servoce/utests/face.cpp -o CMakeFiles/servoce_test.dir/utests/face.cpp.s

CMakeFiles/servoce_test.dir/utests/face.cpp.o.requires:

.PHONY : CMakeFiles/servoce_test.dir/utests/face.cpp.o.requires

CMakeFiles/servoce_test.dir/utests/face.cpp.o.provides: CMakeFiles/servoce_test.dir/utests/face.cpp.o.requires
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/face.cpp.o.provides.build
.PHONY : CMakeFiles/servoce_test.dir/utests/face.cpp.o.provides

CMakeFiles/servoce_test.dir/utests/face.cpp.o.provides.build: CMakeFiles/servoce_test.dir/utests/face.cpp.o


CMakeFiles/servoce_test.dir/utests/main.cpp.o: CMakeFiles/servoce_test.dir/flags.make
CMakeFiles/servoce_test.dir/utests/main.cpp.o: utests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mirmik/project/servoce/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/servoce_test.dir/utests/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servoce_test.dir/utests/main.cpp.o -c /home/mirmik/project/servoce/utests/main.cpp

CMakeFiles/servoce_test.dir/utests/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servoce_test.dir/utests/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mirmik/project/servoce/utests/main.cpp > CMakeFiles/servoce_test.dir/utests/main.cpp.i

CMakeFiles/servoce_test.dir/utests/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servoce_test.dir/utests/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mirmik/project/servoce/utests/main.cpp -o CMakeFiles/servoce_test.dir/utests/main.cpp.s

CMakeFiles/servoce_test.dir/utests/main.cpp.o.requires:

.PHONY : CMakeFiles/servoce_test.dir/utests/main.cpp.o.requires

CMakeFiles/servoce_test.dir/utests/main.cpp.o.provides: CMakeFiles/servoce_test.dir/utests/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/main.cpp.o.provides.build
.PHONY : CMakeFiles/servoce_test.dir/utests/main.cpp.o.provides

CMakeFiles/servoce_test.dir/utests/main.cpp.o.provides.build: CMakeFiles/servoce_test.dir/utests/main.cpp.o


CMakeFiles/servoce_test.dir/utests/solid.cpp.o: CMakeFiles/servoce_test.dir/flags.make
CMakeFiles/servoce_test.dir/utests/solid.cpp.o: utests/solid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mirmik/project/servoce/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/servoce_test.dir/utests/solid.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servoce_test.dir/utests/solid.cpp.o -c /home/mirmik/project/servoce/utests/solid.cpp

CMakeFiles/servoce_test.dir/utests/solid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servoce_test.dir/utests/solid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mirmik/project/servoce/utests/solid.cpp > CMakeFiles/servoce_test.dir/utests/solid.cpp.i

CMakeFiles/servoce_test.dir/utests/solid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servoce_test.dir/utests/solid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mirmik/project/servoce/utests/solid.cpp -o CMakeFiles/servoce_test.dir/utests/solid.cpp.s

CMakeFiles/servoce_test.dir/utests/solid.cpp.o.requires:

.PHONY : CMakeFiles/servoce_test.dir/utests/solid.cpp.o.requires

CMakeFiles/servoce_test.dir/utests/solid.cpp.o.provides: CMakeFiles/servoce_test.dir/utests/solid.cpp.o.requires
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/solid.cpp.o.provides.build
.PHONY : CMakeFiles/servoce_test.dir/utests/solid.cpp.o.provides

CMakeFiles/servoce_test.dir/utests/solid.cpp.o.provides.build: CMakeFiles/servoce_test.dir/utests/solid.cpp.o


CMakeFiles/servoce_test.dir/utests/trans.cpp.o: CMakeFiles/servoce_test.dir/flags.make
CMakeFiles/servoce_test.dir/utests/trans.cpp.o: utests/trans.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mirmik/project/servoce/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/servoce_test.dir/utests/trans.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servoce_test.dir/utests/trans.cpp.o -c /home/mirmik/project/servoce/utests/trans.cpp

CMakeFiles/servoce_test.dir/utests/trans.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servoce_test.dir/utests/trans.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mirmik/project/servoce/utests/trans.cpp > CMakeFiles/servoce_test.dir/utests/trans.cpp.i

CMakeFiles/servoce_test.dir/utests/trans.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servoce_test.dir/utests/trans.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mirmik/project/servoce/utests/trans.cpp -o CMakeFiles/servoce_test.dir/utests/trans.cpp.s

CMakeFiles/servoce_test.dir/utests/trans.cpp.o.requires:

.PHONY : CMakeFiles/servoce_test.dir/utests/trans.cpp.o.requires

CMakeFiles/servoce_test.dir/utests/trans.cpp.o.provides: CMakeFiles/servoce_test.dir/utests/trans.cpp.o.requires
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/trans.cpp.o.provides.build
.PHONY : CMakeFiles/servoce_test.dir/utests/trans.cpp.o.provides

CMakeFiles/servoce_test.dir/utests/trans.cpp.o.provides.build: CMakeFiles/servoce_test.dir/utests/trans.cpp.o


CMakeFiles/servoce_test.dir/utests/wire.cpp.o: CMakeFiles/servoce_test.dir/flags.make
CMakeFiles/servoce_test.dir/utests/wire.cpp.o: utests/wire.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mirmik/project/servoce/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/servoce_test.dir/utests/wire.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servoce_test.dir/utests/wire.cpp.o -c /home/mirmik/project/servoce/utests/wire.cpp

CMakeFiles/servoce_test.dir/utests/wire.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servoce_test.dir/utests/wire.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mirmik/project/servoce/utests/wire.cpp > CMakeFiles/servoce_test.dir/utests/wire.cpp.i

CMakeFiles/servoce_test.dir/utests/wire.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servoce_test.dir/utests/wire.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mirmik/project/servoce/utests/wire.cpp -o CMakeFiles/servoce_test.dir/utests/wire.cpp.s

CMakeFiles/servoce_test.dir/utests/wire.cpp.o.requires:

.PHONY : CMakeFiles/servoce_test.dir/utests/wire.cpp.o.requires

CMakeFiles/servoce_test.dir/utests/wire.cpp.o.provides: CMakeFiles/servoce_test.dir/utests/wire.cpp.o.requires
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/wire.cpp.o.provides.build
.PHONY : CMakeFiles/servoce_test.dir/utests/wire.cpp.o.provides

CMakeFiles/servoce_test.dir/utests/wire.cpp.o.provides.build: CMakeFiles/servoce_test.dir/utests/wire.cpp.o


# Object files for target servoce_test
servoce_test_OBJECTS = \
"CMakeFiles/servoce_test.dir/utests/curve3.cpp.o" \
"CMakeFiles/servoce_test.dir/utests/face.cpp.o" \
"CMakeFiles/servoce_test.dir/utests/main.cpp.o" \
"CMakeFiles/servoce_test.dir/utests/solid.cpp.o" \
"CMakeFiles/servoce_test.dir/utests/trans.cpp.o" \
"CMakeFiles/servoce_test.dir/utests/wire.cpp.o"

# External object files for target servoce_test
servoce_test_EXTERNAL_OBJECTS =

servoce_test: CMakeFiles/servoce_test.dir/utests/curve3.cpp.o
servoce_test: CMakeFiles/servoce_test.dir/utests/face.cpp.o
servoce_test: CMakeFiles/servoce_test.dir/utests/main.cpp.o
servoce_test: CMakeFiles/servoce_test.dir/utests/solid.cpp.o
servoce_test: CMakeFiles/servoce_test.dir/utests/trans.cpp.o
servoce_test: CMakeFiles/servoce_test.dir/utests/wire.cpp.o
servoce_test: CMakeFiles/servoce_test.dir/build.make
servoce_test: libservoce.so
servoce_test: CMakeFiles/servoce_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mirmik/project/servoce/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable servoce_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/servoce_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/servoce_test.dir/build: servoce_test

.PHONY : CMakeFiles/servoce_test.dir/build

CMakeFiles/servoce_test.dir/requires: CMakeFiles/servoce_test.dir/utests/curve3.cpp.o.requires
CMakeFiles/servoce_test.dir/requires: CMakeFiles/servoce_test.dir/utests/face.cpp.o.requires
CMakeFiles/servoce_test.dir/requires: CMakeFiles/servoce_test.dir/utests/main.cpp.o.requires
CMakeFiles/servoce_test.dir/requires: CMakeFiles/servoce_test.dir/utests/solid.cpp.o.requires
CMakeFiles/servoce_test.dir/requires: CMakeFiles/servoce_test.dir/utests/trans.cpp.o.requires
CMakeFiles/servoce_test.dir/requires: CMakeFiles/servoce_test.dir/utests/wire.cpp.o.requires

.PHONY : CMakeFiles/servoce_test.dir/requires

CMakeFiles/servoce_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/servoce_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/servoce_test.dir/clean

CMakeFiles/servoce_test.dir/depend:
	cd /home/mirmik/project/servoce && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mirmik/project/servoce /home/mirmik/project/servoce /home/mirmik/project/servoce /home/mirmik/project/servoce /home/mirmik/project/servoce/CMakeFiles/servoce_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/servoce_test.dir/depend

