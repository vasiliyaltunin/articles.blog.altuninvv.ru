cmake_minimum_required(VERSION 3.16)

# Задаем имя проекта
project(colorconsoleapp VERSION 0.1 LANGUAGES CXX)


# Задаем переменные и настройки для использования
include(${PROJECT_SOURCE_DIR}/cmake/settings.cmake.in)

# Настраиваем WIX
include(${PROJECT_SOURCE_DIR}/cmake/wix.cmake.in)

# Настраиваем зависимости и устанавливаем библиотеки из git-репозиториев
include(${PROJECT_SOURCE_DIR}/cmake/git.cmake.in)

# Задаем настройки сборки программы
include(${PROJECT_SOURCE_DIR}/cmake/conf.cmake.in)

# Задаем targets для библиотеки
include(${PROJECT_SOURCE_DIR}/cmake/targets.cmake.in)

# Настраиваем установку разделяемых (shared) библиотек
include(${PROJECT_SOURCE_DIR}/cmake/shared_deps.cmake.in)

# Настраиваем установку проекта
include(${PROJECT_SOURCE_DIR}/cmake/install.cmake.in)
