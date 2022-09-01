# CMake generated Testfile for 
# Source directory: /home/jhow/mano/containers/tests
# Build directory: /home/jhow/mano/containers/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("/home/jhow/mano/containers/build/my_test_container[1]_include.cmake")
add_test(my_test_container "/home/jhow/mano/containers/build/my_test_container")
set_tests_properties(my_test_container PROPERTIES  _BACKTRACE_TRIPLES "/home/jhow/mano/containers/tests/CMakeLists.txt;17;add_test;/home/jhow/mano/containers/tests/CMakeLists.txt;0;")
add_test(original_test_container "/home/jhow/mano/containers/build/original_test_container")
set_tests_properties(original_test_container PROPERTIES  _BACKTRACE_TRIPLES "/home/jhow/mano/containers/tests/CMakeLists.txt;24;add_test;/home/jhow/mano/containers/tests/CMakeLists.txt;0;")
subdirs("googletest")
