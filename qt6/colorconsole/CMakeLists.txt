cmake_minimum_required(VERSION 3.16)

project(colorconsoleapp VERSION 0.1 LANGUAGES CXX)

find_package(colorconsole CONFIG REQUIRED) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp        
)

include(GNUInstallDirs)

target_link_libraries(${PROJECT_NAME} ccon::colorconsole)
