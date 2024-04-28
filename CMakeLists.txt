cmake_minimum_required(VERSION 3.27)
project(CA2_Bugs_Life)

set(CMAKE_CXX_STANDARD 17)

add_executable(CA2_Bugs_Life main.cpp
        Bug.h
        Bug.cpp
        Crawler.cpp
        Crawler.h
        Hopper.cpp
        Hopper.h
        Board.h
        Board.cpp
        Directions.h
        Directions.h
        Ladybird.h
        Ladybird.cpp)

