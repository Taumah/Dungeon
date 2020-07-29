cmake_minimum_required(VERSION 3.9)

project(Dungeon)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCE_FILES src/main.c src/utils.c)

add_executable(Dungeon ${SOURCE_FILES})
target_link_libraries(Dungeon ${SDL2_LIBRARIES})