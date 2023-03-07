cmake_minimum_required(VERSION 3.2)

project(supermarket)

set(CMAKE_BUILD_TYPE "Debug")

find_package(glfw3 3.3 REQUIRED)

set(SRC src/main.cpp
  src/game/game.cpp
  src/engine/app.cpp
  src/engine/context.cpp
  src/engine/math.cpp
  src/engine/color.cpp
  src/engine/command.cpp
  src/engine/events.cpp
  src/engine/gl/gl.c)

add_executable(supermarket ${SRC})
target_include_directories(supermarket PUBLIC include)

target_link_libraries(supermarket glfw)
