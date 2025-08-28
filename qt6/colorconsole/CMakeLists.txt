cmake_minimum_required(VERSION 3.16)

project(colorconsoleapp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp        
	colorconsole.cpp
	colorconsole.h 
)

include(GNUInstallDirs)