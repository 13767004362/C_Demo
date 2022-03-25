cmake_minimum_required(VERSION 3.12)
project(demo)

set(CMAKE_CXX_STANDARD 14)

add_executable(demo    studyDemo/thread/ThreadDemo.cpp studyDemo/thread/ThreadDemo.h)
#add_executable(demo   studyDemo/string/StringDemo.cpp)