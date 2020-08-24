cmake_minimum_required(VERSION 2.4)

project(algorithm_study)

include_directories(~/Exercise/algorithm)
set(SRC_FILES leet_code/0824.cc)
#set(SRC_FILES jongman_book/data_structure/running_median2.cc)
add_executable(app ${SRC_FILES})
