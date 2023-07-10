cmake_minimum_required(VERSION 3.16)

project(Main LANGUAGES CXX)

# LINK_DIRECTORIES(/usr/local/lib)
LINK_DIRECTORIES(./different_api/m300 ./different_api/m600 ./different_api/mavic ./different_api/skydio)

LINK_LIBRARIES(libdji_m300_api.so libdji_m600_api.so libdji_mavic_api.so libskydio_api.so)

add_executable (program Main.cpp)


# gTest
enable_testing() #to  discover tests in test explorer 

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(myTest myTest.cpp) # add this executable

target_link_libraries(myTest PRIVATE gtest) # link google test to this executable

include(GoogleTest)

gtest_discover_tests(myTest) # discovers tests by asking the compiled test executable to enumerate its tests