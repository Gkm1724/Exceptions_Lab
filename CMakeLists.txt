cmake_minimum_required(VERSION 4.0)
project(Exceptions)

set(CMAKE_CXX_STANDARD 20)

add_executable(Exceptions
        main.cpp
        GeometryUtils.cpp
        GeometryUtils.h
        FileUtils.cpp
        FileUtils.h
        Exceptions.cpp
        Exceptions.h)
