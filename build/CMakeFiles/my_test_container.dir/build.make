# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/jhow/mano/containers/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jhow/mano/containers/build

# Include any dependencies generated for this target.
include CMakeFiles/my_test_container.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_test_container.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_test_container.dir/flags.make

CMakeFiles/my_test_container.dir/test.cpp.o: CMakeFiles/my_test_container.dir/flags.make
CMakeFiles/my_test_container.dir/test.cpp.o: /home/jhow/mano/containers/tests/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jhow/mano/containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_test_container.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_test_container.dir/test.cpp.o -c /home/jhow/mano/containers/tests/test.cpp

CMakeFiles/my_test_container.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_test_container.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jhow/mano/containers/tests/test.cpp > CMakeFiles/my_test_container.dir/test.cpp.i

CMakeFiles/my_test_container.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_test_container.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jhow/mano/containers/tests/test.cpp -o CMakeFiles/my_test_container.dir/test.cpp.s

CMakeFiles/my_test_container.dir/check_type_test.cpp.o: CMakeFiles/my_test_container.dir/flags.make
CMakeFiles/my_test_container.dir/check_type_test.cpp.o: /home/jhow/mano/containers/tests/check_type_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jhow/mano/containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my_test_container.dir/check_type_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_test_container.dir/check_type_test.cpp.o -c /home/jhow/mano/containers/tests/check_type_test.cpp

CMakeFiles/my_test_container.dir/check_type_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_test_container.dir/check_type_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jhow/mano/containers/tests/check_type_test.cpp > CMakeFiles/my_test_container.dir/check_type_test.cpp.i

CMakeFiles/my_test_container.dir/check_type_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_test_container.dir/check_type_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jhow/mano/containers/tests/check_type_test.cpp -o CMakeFiles/my_test_container.dir/check_type_test.cpp.s

CMakeFiles/my_test_container.dir/utility_test.cpp.o: CMakeFiles/my_test_container.dir/flags.make
CMakeFiles/my_test_container.dir/utility_test.cpp.o: /home/jhow/mano/containers/tests/utility_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jhow/mano/containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/my_test_container.dir/utility_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_test_container.dir/utility_test.cpp.o -c /home/jhow/mano/containers/tests/utility_test.cpp

CMakeFiles/my_test_container.dir/utility_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_test_container.dir/utility_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jhow/mano/containers/tests/utility_test.cpp > CMakeFiles/my_test_container.dir/utility_test.cpp.i

CMakeFiles/my_test_container.dir/utility_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_test_container.dir/utility_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jhow/mano/containers/tests/utility_test.cpp -o CMakeFiles/my_test_container.dir/utility_test.cpp.s

CMakeFiles/my_test_container.dir/my_vector_test.cpp.o: CMakeFiles/my_test_container.dir/flags.make
CMakeFiles/my_test_container.dir/my_vector_test.cpp.o: /home/jhow/mano/containers/tests/my_vector_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jhow/mano/containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/my_test_container.dir/my_vector_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_test_container.dir/my_vector_test.cpp.o -c /home/jhow/mano/containers/tests/my_vector_test.cpp

CMakeFiles/my_test_container.dir/my_vector_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_test_container.dir/my_vector_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jhow/mano/containers/tests/my_vector_test.cpp > CMakeFiles/my_test_container.dir/my_vector_test.cpp.i

CMakeFiles/my_test_container.dir/my_vector_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_test_container.dir/my_vector_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jhow/mano/containers/tests/my_vector_test.cpp -o CMakeFiles/my_test_container.dir/my_vector_test.cpp.s

CMakeFiles/my_test_container.dir/my_map_test.cpp.o: CMakeFiles/my_test_container.dir/flags.make
CMakeFiles/my_test_container.dir/my_map_test.cpp.o: /home/jhow/mano/containers/tests/my_map_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jhow/mano/containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/my_test_container.dir/my_map_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_test_container.dir/my_map_test.cpp.o -c /home/jhow/mano/containers/tests/my_map_test.cpp

CMakeFiles/my_test_container.dir/my_map_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_test_container.dir/my_map_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jhow/mano/containers/tests/my_map_test.cpp > CMakeFiles/my_test_container.dir/my_map_test.cpp.i

CMakeFiles/my_test_container.dir/my_map_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_test_container.dir/my_map_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jhow/mano/containers/tests/my_map_test.cpp -o CMakeFiles/my_test_container.dir/my_map_test.cpp.s

# Object files for target my_test_container
my_test_container_OBJECTS = \
"CMakeFiles/my_test_container.dir/test.cpp.o" \
"CMakeFiles/my_test_container.dir/check_type_test.cpp.o" \
"CMakeFiles/my_test_container.dir/utility_test.cpp.o" \
"CMakeFiles/my_test_container.dir/my_vector_test.cpp.o" \
"CMakeFiles/my_test_container.dir/my_map_test.cpp.o"

# External object files for target my_test_container
my_test_container_EXTERNAL_OBJECTS =

my_test_container: CMakeFiles/my_test_container.dir/test.cpp.o
my_test_container: CMakeFiles/my_test_container.dir/check_type_test.cpp.o
my_test_container: CMakeFiles/my_test_container.dir/utility_test.cpp.o
my_test_container: CMakeFiles/my_test_container.dir/my_vector_test.cpp.o
my_test_container: CMakeFiles/my_test_container.dir/my_map_test.cpp.o
my_test_container: CMakeFiles/my_test_container.dir/build.make
my_test_container: lib/libgtest_main.a
my_test_container: lib/libgtest.a
my_test_container: CMakeFiles/my_test_container.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jhow/mano/containers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable my_test_container"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_test_container.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=my_test_container -D TEST_EXECUTABLE=/home/jhow/mano/containers/build/my_test_container -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/jhow/mano/containers/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=my_test_container_TESTS -D CTEST_FILE=/home/jhow/mano/containers/build/my_test_container[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -P /usr/share/cmake-3.16/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/my_test_container.dir/build: my_test_container

.PHONY : CMakeFiles/my_test_container.dir/build

CMakeFiles/my_test_container.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_test_container.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_test_container.dir/clean

CMakeFiles/my_test_container.dir/depend:
	cd /home/jhow/mano/containers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jhow/mano/containers/tests /home/jhow/mano/containers/tests /home/jhow/mano/containers/build /home/jhow/mano/containers/build /home/jhow/mano/containers/build/CMakeFiles/my_test_container.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_test_container.dir/depend

