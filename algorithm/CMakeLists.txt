cmake_minimum_required(VERSION 2.4)

project(algorithm_study)

include_directories(~/Exercise/algorithm)
set(SRC_FILES dynamic_program/packing2.cc)
add_executable(app ${SRC_FILES})
