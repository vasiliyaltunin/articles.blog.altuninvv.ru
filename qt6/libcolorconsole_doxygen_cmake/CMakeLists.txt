cmake_minimum_required(VERSION 3.14)

# Имя оно же target проекта, его описание и язык
project(colorconsole
    VERSION 0.1.0
    DESCRIPTION "Библиотека для вывода цветного текста в консоль"
    LANGUAGES CXX)

# Загружаем данные о путях до папок в которые установлены библиотеки C++
include(GNUInstallDirs)
# Загружаем модули CMake
include(GenerateExportHeader)
include(CMakePackageConfigHelpers)


# Задаем переменные и настройки для использования
include(${PROJECT_SOURCE_DIR}/cmake/settings.cmake.in)

# Задаем настройки самой библиотеки и её тип
include(${PROJECT_SOURCE_DIR}/cmake/libconf.cmake.in)

# Задаем targets для библиотеки
include(${PROJECT_SOURCE_DIR}/cmake/targets.cmake.in)

# Задаем настройки установки для библиотеки
include(${PROJECT_SOURCE_DIR}/cmake/install.cmake.in)