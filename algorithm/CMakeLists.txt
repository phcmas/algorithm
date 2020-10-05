cmake_minimum_required(VERSION 2.4)

project(algorithm_study)
#add_compile_options(-Wall -std=c++14 -O2 -fPIC)

include_directories(~/Exercise/algorithm)
set(SRC_FILES leet_code/1005.cc)
#set(SRC_FILES jongman_book/shortest_path/routing.cc)
add_executable(app ${SRC_FILES})
