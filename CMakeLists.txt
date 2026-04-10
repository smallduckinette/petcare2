cmake_minimum_required(VERSION 3.28)
project(petcare)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 26)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(fmt REQUIRED)


add_executable(
  petcare
  petcare.cpp
)

target_link_libraries(
  petcare
  SDL2::Main
  SDL2::Image
  SDL2::TTF
  SDL2::Mixer
  fmt::fmt)
