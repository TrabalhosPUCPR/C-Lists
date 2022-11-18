cmake_minimum_required(VERSION 3.24)
project(DataStructures C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStructures main.c lists/list.c lists/list.h lists/linkedlist.c lists/linkedlist.h lists/Lists.h lists/queue.c lists/queue.h lists/stack.c lists/stack.h)
