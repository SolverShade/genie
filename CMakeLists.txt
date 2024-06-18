cmake_minimum_required(VERSION 3.10) 

project(genie)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_executable(genie "${CMAKE_SOURCE_DIR}/src/main.cpp")
target_link_libraries(genie 
  glfw
  imgui::imgui
)
