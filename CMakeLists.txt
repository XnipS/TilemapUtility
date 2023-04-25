cmake_minimum_required(VERSION 3.5)

project(TilemapUtility LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h)

add_library(lib-TilemapUtility SHARED
${SOURCE_FILES}
${HEADER_FILES}
)

add_executable(TilemapUtility src/main.cpp)

target_link_libraries(TilemapUtility lib-TilemapUtility)