cmake_minimum_required(VERSION 3.16)

project(M300API LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(M300_API_SRCS
    gps/gps.cc
    navigation/navigation.cc
    sensor_data/sensor_data.cc
    status/status.cc
)

#add_library(nlablib STATIC IMPORTED)
#set_property(TARGET nlablib PROPERTY
#            IMPORTED_LOCATION "/usr/local/lib/libnlablib.so")

add_library(dji_m300_api SHARED
  ${M300_API_SRCS}
)

include_directories(dji_m300_api
	${PROJECT_SOURCE_DIR}
)

# Installation
file(GLOB M300_API_HEADERS
    gps/gps.h
    navigation/navigation.h
    sensor_data/sensor_data.h
    status/status.h
)

set_target_properties(dji_m300_api PROPERTIES
        PUBLIC_HEADER "${M300_API_HEADERS}")

install(TARGETS dji_m300_api DESTINATION lib
        PERMISSIONS WORLD_EXECUTE WORLD_READ WORLD_WRITE GROUP_EXECUTE GROUP_READ GROUP_WRITE OWNER_EXECUTE OWNER_WRITE OWNER_READ
        PUBLIC_HEADER           DESTINATION include/M300_API)
        
#add_subdirectory(test)