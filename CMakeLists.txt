cmake_minimum_required(VERSION 3.16)

project(Main LANGUAGES CXX)

LINK_DIRECTORIES(/usr/local/lib)

LINK_LIBRARIES(libdji_m300_api.so libdji_m600_api.so libdji_mavic_api.so libskydio_api.so)

add_executable (program Main.cpp)


