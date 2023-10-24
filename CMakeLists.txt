cmake_minimum_required(VERSION 3.15)
project(6502EmulatorRenderer VERSION 0.1.0 LANGUAGES C CXX)

set(PROJECT_INCLUDE_DIR 6502EmulatorRenderer)
set(CMAKE_CXX_STANDARD 20)

include_directories(
    ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/include
    # Uncomment these if you want to directly includes the directories themselves
    # Example: instead of doing: #include "common/Utils.h" you would just be doing "Utils.h"
    # ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/include/common
    # ${PROJECT_SOURCE_DIR}/${PROJECT_INCLUDE_DIR}/include/core
)

find_package(LibA REQUIRED)

set(
    all_src
    ${PROJECT_INCLUDE_DIR}/src/core/Window.cpp
    main.cpp
)



add_executable(${PROJECT_NAME} ${all_src})

target_link_libraries(${PROJECT_NAME} LibA)
include(${PROJECT_SOURCE_DIR}/cmake/glfw.cmake)
# include(${PROJECT_SOURCE_DIR}/cmake/opencv.cmake)
# # include(${PROJECT_SOURCE_DIR}/cmake/assimp.cmake)
# include(${PROJECT_SOURCE_DIR}/cmake/ffmpeg.cmake)