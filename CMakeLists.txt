cmake_minimum_required(VERSION 3.28)
project(petcare)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 26)

find_package(SFML COMPONENTS window graphics system)
find_package(fmt REQUIRED)

add_executable(
  petcare
  src/petcare.cpp
)

target_link_libraries(
  petcare
  fmt::fmt
  sfml-window
  sfml-graphics
  sfml-system)
