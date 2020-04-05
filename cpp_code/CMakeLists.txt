cmake_minimum_required(VERSION 2.4)

project(hello_world)

include_directories(~/Exercise/cpp_code)
add_executable(app linked_list.cc node.cc stack.cc test.cc queue.cc algorithm.h)
