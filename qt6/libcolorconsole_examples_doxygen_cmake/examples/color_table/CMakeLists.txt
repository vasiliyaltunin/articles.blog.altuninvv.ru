cmake_minimum_required(VERSION 3.16)

project(color_table_example VERSION 0.1 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
        ..\\..\\src\\colorconsole.h 
        ..\\..\\src\\colorconsole.cpp
        main.cpp
)

include(GNUInstallDirs)