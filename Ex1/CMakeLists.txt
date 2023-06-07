# Note: CMake support is community-based. The maintainers do not use CMake
# internally.

cmake_minimum_required(VERSION 3.5)

project(my_cpp_project) #name of your project

enable_testing() #to  discover tests in test explorer 

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(myTest myTest.cpp) # add this executable

target_link_libraries(myTest PRIVATE gtest) # link google test to this executable

include(GoogleTest)

gtest_discover_tests(myTest) # discovers tests by asking the compiled test executable to enumerate its tests
