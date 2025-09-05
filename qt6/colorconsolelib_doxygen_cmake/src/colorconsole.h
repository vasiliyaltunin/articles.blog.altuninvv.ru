/**
 * @file colorconsole.cpp
 * @author Василий Алтунин (skyr@altuninvv.ru)
 * @brief Файл содержит реализацию класса ColorConsole
 * @version 0.1.0
 * @date 2025-09-02
 *
 * @copyright Алтунин Василий 2025
 *
 */

#ifndef COLORCONSOLE_H
#define COLORCONSOLE_H

#include <windows.h>

namespace ccon
{

class ColorConsole
{

public:

   
    /// @brief Черный   
    static const int BLACK = 0;

    /// @brief Темно-синий
    static const int DARK_BLUE = 1;

    /// @brief Темно-зеленый
    static const int DARK_GREEN = 2;

    /// @brief Темно-салатовый
    static const int DARK_CYAN = 3;

    /// @brief Темно-красный
    static const int DARK_RED = 4;

    /// @brief Темно-фиолетовый
    static const int DARK_MAGENTA = 5;

    /// @brief Темно-желтый
    static const int DARK_YELLOW = 6;

    /// @brief Светло-серый
    static const int LIGHT_GRAY = 7;

    /// @brief Темно-серый
    static const int DARK_GRAY = 8;

    /// @brief Светло-синий
    static const int LIGHT_BLUE = 9;

    /// @brief Светло-зеленый
    static const int LIGHT_GREEN = 10;

    /// @brief Светло-салатовый
    static const int LIGHT_CYAN = 11;

    /// @brief Светло-красный
    static const int LIGHT_RED = 12;

    /// @brief Светло-фиолетовый
    static const int LIGHT_MAGENTA = 13;

    /// @brief Светло-желтый
    static const int LIGHT_YELLOW = 14;

    /// @brief Белый
    static const int WHITE = 15;

    /**
     * @brief Конструктор класса ColorConsole
     *
     */
    ColorConsole();

    /**
     * @brief Деструктор класса ColorConsole
     *
     */
    ~ColorConsole();

    /**
     * @brief Инициализирует статические дескрипторы консоли
     * Обязательно должна быть вызвана перед использованием методов 
     * класса меняющих цвет текста в консоли!
     *  @param Returns Ничего не возвращает
     *
     */
    static void init();

    /**
     * @brief Дискриптор консоли stdout
     * 
     */
    static HANDLE __console_stdout_handle;
    /**
     * @brief Дискриптор консоли stderr
     * 
     */
    static HANDLE __console_stderr_handle;

    /**
     * @brief Устанавливает цвет текста и фона для консоли stdout
     *
     * @param color цвет текста
     * @param bgColor цвет фона
     * @param Returns Ничего не возвращает
     *   
     */
    static void setConsStdOutColor(int color, int bgColor = 0);

    /**
     * @brief Устанавливает цвет текста и фона для консоли stderr
     *
     * @param color цвет текста
     * @param bgColor цвет фона
     * @param Returns Ничего не возвращает
     *
     */
    static void setConsStdErrColor(int color, int bgColor = 0);

    /**
     * @brief Устанавливает цвет по умолчанию для консоли stdout (черный фон серый текст)
     * @param Returns
     *    Ничего не возвращает
     *
     */
    static void setConsStdOutDefColor();

    /**
     * @brief Устанавливает цвет по умолчанию для консоли stderr (черный фон серый текст)
     * @param Returns
     *    Ничего не возвращает
     *
     */
    static void setConsStdErrDefColor();

    /**
     * @brief Добавляет пустую линию с цветом по умолчанию (черный фон)
     * @param Returns
     *    Ничего не возвращает
     *
     */
    static void emptyLine();
};

}

#endif