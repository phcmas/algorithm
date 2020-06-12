cmake_minimum_required(VERSION 2.4)

project(algorithm_study)

include_directories(~/Exercise/algorithm)
set(SRC_FILES jongman_book/dynamic_program/dragon.cc)
add_executable(app ${SRC_FILES})
