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
        Ladybird.cpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML-2.6.1/include)

target_link_libraries(CA2_Bugs_Life sfml-system sfml-window sfml-graphics sfml-audio)
