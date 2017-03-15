cmake_minimum_required(VERSION 2.8)

project(ukuleleFactory)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

FIND_PACKAGE(Qt4 REQUIRED)
if (Qt_FOUND)

else
