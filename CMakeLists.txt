cmake_minimum_required(VERSION 3.19)
project(GTKRuler3_example)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(GTKRuler3_example ${SOURCE_FILES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
find_package(Cairo)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
include_directories(${Cairo_INCLUDE_DIRS})
target_link_libraries(GTKRuler3_example ${Cairo_LIBRARIES})
add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(GTKRuler3_example ${GTK3_LIBRARIES})
add_subdirectory(GTKRuler3)
target_link_libraries(GTKRuler3_example GTKRuler3)