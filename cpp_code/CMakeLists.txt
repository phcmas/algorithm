cmake_minimum_required(VERSION 2.4)

project(hello_world)

include_directories(~/Exercise/cpp_code)
set(SRC_FILES binary_tree.cc graph.cc linked_list.cc node.cc priority_queue.cc queue.cc stack.cc test.cc sort_algorithm.h)
add_executable(app ${SRC_FILES})
