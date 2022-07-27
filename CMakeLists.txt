#cmake 版本
cmake_minimum_required(VERSION 3.12)

#项目工程名为demo
project(demo)

# 这里使用C++ 14
set(CMAKE_CXX_STANDARD 14)

#定义referenceDemo 的变量
set(referenceDemo studyDemo/reference/ReferenceDemo.cpp)

#add_executable(demo    studyDemo/thread/ThreadDemo.cpp studyDemo/thread/ThreadDemo.h)
#全部.cpp文件编译成一个可执行程序
add_executable(demo   ${referenceDemo})