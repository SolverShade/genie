cmake_minimum_required(VERSION 3.20)

project(glad)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_CURRENT_LIST_DIR}/src)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include/glad)

message(STATUS "glad source: ${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE SOURCE_FILES
   "${CMAKE_CURRENT_LIST_DIR}/*.cpp"
   "${CMAKE_CURRENT_LIST_DIR}/*.h"
   "${CMAKE_CURRENT_LIST_DIR}/*.hpp"
)

add_executable(glad "${CMAKE_CURRENT_LIST_DIR}/src/glad.c" ${SOURCE_FILES})
#target_link_libraries(genie nanogui ${NANOGUI_EXTRA_LIBS} glad)

