cmake_minimum_required(VERSION 2.4)

project(algorithm_study)
#add_compile_options(-Wall -std=c++11 -O2 -fPIC)

include_directories(~/Exercise/algorithm)
set(SRC_FILES leet_code/2020_12/1212.cc)
#set(SRC_FILES jongman_book/shortest_path/firetruck.cc)
#set(SRC_FILES programmers/2020_11/1105_3.cc)
add_executable(app ${SRC_FILES})
