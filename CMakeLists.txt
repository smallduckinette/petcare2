cmake_minimum_required(VERSION 3.28)
project(petcare)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 26)

find_package(SFML COMPONENTS window graphics system)
find_package(fmt REQUIRED)
find_package(Boost COMPONENTS program_options REQUIRED)

add_executable(
  petcare
  src/GraphicsSubsystem.cpp
  src/InputSubsystem.cpp
  src/petcare.cpp
)

target_link_libraries(
  petcare
  Boost::program_options
  fmt::fmt
  sfml-window
  sfml-graphics
  sfml-system)
