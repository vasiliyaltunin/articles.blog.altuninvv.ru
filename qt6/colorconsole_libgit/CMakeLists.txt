cmake_minimum_required(VERSION 3.16)

project(colorconsoleapp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Собираем исключительно статическую версию программы и библиотеки 
set(BUILD_SHARED_LIBS ON CACHE INTERNAL "Build using shared libraries ON/OFF")

# Подключаем модуль FetchContent
include(FetchContent)

# Отключаем тихий режим работы FetchContent
set(FETCHCONTENT_QUIET FALSE)

# Задаем настройки для загрузки из git-репозитория
FetchContent_Declare(
  colorconsole  # Имя target нашей библиотеки, должно совпадать с используемым далее 
  GIT_REPOSITORY https://gitflic.ru/project/vasiliyaltunin/color-console-library.git # Путь до репозитория
  GIT_SHALLOW TRUE # Загружаем только последние коммиты
  GIT_PROGRESS TRUE # Отображаем процесс загрузки
  USES_TERMINAL_DOWNLOAD TRUE # Отображать прогресс в терминале (только для Ninja)
  SYSTEM
)

# Запускаем загрузку из git-репозитория и подключение библиотеки
FetchContent_MakeAvailable(colorconsole)


add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp       
)

include(GNUInstallDirs)

target_link_libraries(${PROJECT_NAME} PRIVATE ccon::colorconsole)

message(BUILD_SHARED_LIBS = ${BUILD_SHARED_LIBS})

# Копируем разделяемую библоитеку из папки сборки библиотеки в папку сборки нашего проекта
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
               ${colorconsole_BINARY_DIR}/libcolorconsole.dll
               ${CMAKE_CURRENT_BINARY_DIR}/libcolorconsole.dll)