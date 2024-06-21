cmake_minimum_required(VERSION 3.20)

project(genie)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)

include("~/source/tools/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCE_FILES
   "${PROJECT_SOURCE_DIR}/src/*.cpp"
   "${PROJECT_SOURCE_DIR}/src/*.h"
   "${PROJECT_SOURCE_DIR}/src/*.hpp"
)

add_executable(genie "${CMAKE_SOURCE_DIR}/src/main.cpp" ${SOURCE_FILES})
target_link_libraries(genie
  glfw
  imgui::imgui
  glad::glad
  ${OPENGL_LIBRARIES}
)

target_include_directories(genie PRIVATE ${OPENGL_INCLUDE_DIR})

