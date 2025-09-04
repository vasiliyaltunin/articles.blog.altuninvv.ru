/**
 * @file colorconsole.cpp
 * @author Василий Алтунин (skyr@altuninvv.ru)
 * @brief Файл содержит реализацию класса ColorConsole
 * @version 0.1.0
 * @date 02.09.2025
 *
 * @copyright Алтунин Василий 2025
 * 
 * Файл содержит реализацию класса ColorConsole позволяющего менять цвет текста и фона в консоли Windows.
 *
 */

#include "colorconsole.h"
#include <iostream>

namespace ccon
{

/**
 * @brief Конструктор класса ColorConsole
 *
 */
ColorConsole::ColorConsole()
{
}

/**
 * @brief Деструктор класса ColorConsole
 *
 */
ColorConsole::~ColorConsole()
{
}

HANDLE ColorConsole::__console_stdout_handle;
HANDLE ColorConsole::__console_stderr_handle;

/**
 * @brief Инициализирует статические дескрипторы консоли
 * Обязательно должна быть вызвана перед использованием методов
 * класса меняющих цвет текста в консоли!
 *  @param Returns Ничего не возвращает
 *
 */
void ColorConsole::init()
{
    ColorConsole::__console_stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    ColorConsole::__console_stderr_handle = GetStdHandle(STD_ERROR_HANDLE);
}

/**
 * @brief Устанавливает цвет текста и фона для консоли stdout
 *
 * @param color цвет текста
 * @param bgColor цвет фона
 * @param Returns Ничего не возвращает
 *
 */
void ColorConsole::setConsStdOutColor(int color, int bgColor)
{
    SetConsoleTextAttribute(ColorConsole::__console_stdout_handle, color + (bgColor * 16));
}

/**
 * @brief Устанавливает цвет текста и фона для консоли stderr
 *
 * @param color цвет текста
 * @param bgColor цвет фона
 * @param Returns Ничего не возвращает
 *
 */
void ColorConsole::setConsStdErrColor(int color, int bgColor)
{
    SetConsoleTextAttribute(ColorConsole::__console_stderr_handle, color + (bgColor * 16));
}

/**
 * @brief Устанавливает цвет по умолчанию для консоли stdout (черный фон серый текст)
 * @param Returns Ничего не возвращает
 *
 */
void ColorConsole::setConsStdOutDefColor()
{
    SetConsoleTextAttribute(ColorConsole::__console_stdout_handle, 7);
}

/**
 * @brief Устанавливает цвет по умолчанию для консоли stderr (черный фон серый текст)
 * @param Returns Ничего не возвращает
 *
 */
void ColorConsole::setConsStdErrDefColor()
{
    SetConsoleTextAttribute(ColorConsole::__console_stderr_handle, 7);
}

/**
 * @brief Добавляет пустую линию с цветом по умолчанию (черный фон)
 * @param Returns Ничего не возвращает
 *
 */

void ColorConsole::emptyLine()
{
    ColorConsole::setConsStdErrDefColor();
    std::cout << std::endl;
}

}