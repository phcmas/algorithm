cmake_minimum_required(VERSION 2.4)

project(algorithm_study)

include_directories(~/Exercise/algorithm)
#set(SRC_FILES leet_code/0826.cc)
set(SRC_FILES jongman_book/dfs/dictionary.cc)
add_executable(app ${SRC_FILES})
