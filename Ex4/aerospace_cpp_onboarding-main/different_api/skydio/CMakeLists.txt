cmake_minimum_required(VERSION 3.16)

project(SKYDIOAPI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SKYDIO_API_SRCS
  gps/gps.cc
  camera/camera.cc
  gimbal/gimbal.cc
  lidar/lidar.cc
  flight_controller/flight_controller.cc
)

add_library(skydio_api SHARED
  ${SKYDIO_API_SRCS}
)

include_directories(skydio_api
	${PROJECT_SOURCE_DIR}
)

# Installation
file(GLOB SKYDIO_API_HEADERS
  gps/gps.h
  flight_controller/flight_controller.h
  gimbal/gimbal.h
  lidar/lidar.h
  camera/camera.h
)

set_target_properties(skydio_api PROPERTIES
        PUBLIC_HEADER "${SKYDIO_API_HEADERS}")

install(TARGETS skydio_api DESTINATION lib
        PERMISSIONS WORLD_EXECUTE WORLD_READ WORLD_WRITE GROUP_EXECUTE GROUP_READ GROUP_WRITE OWNER_EXECUTE OWNER_WRITE OWNER_READ
        PUBLIC_HEADER           DESTINATION include/SKYDIO_API)
        