cmake_minimum_required(VERSION 3.16)

project(colorconsoleapp VERSION 0.1 LANGUAGES CXX)

# Путь для поиска библиотеки с использованием find_package()
list(APPEND CMAKE_PREFIX_PATH "..\\libcolorconsole\\lib\\cmake\\colorconsole\\")

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

find_package(colorconsole CONFIG REQUIRED) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp       
)

include(GNUInstallDirs)

target_link_libraries(${PROJECT_NAME} PRIVATE ccon::colorconsole)

# Путь к заголовочным файлам библиотеки
target_include_directories(${PROJECT_NAME} PRIVATE "..\\libcolorconsole\\include")

message(BUILD_SHARED_LIBS = ${BUILD_SHARED_LIBS})