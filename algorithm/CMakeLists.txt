cmake_minimum_required(VERSION 2.4)

project(algorithm_study)

include_directories(~/Exercise/algorithm)
set(SRC_FILES chess.cc)
add_executable(app ${SRC_FILES})
