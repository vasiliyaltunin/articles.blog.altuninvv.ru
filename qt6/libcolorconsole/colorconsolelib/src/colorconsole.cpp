/****************************************************************************
**
** Copyright 2025 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Класс для вывода цветного текста в консоль
**
****************************************************************************/

#include "colorconsole.h"
#include <iostream>

namespace ccon
{

ColorConsole::ColorConsole()
{
}

ColorConsole::~ColorConsole()
{
}

HANDLE ColorConsole::__console_stdout_handle;
HANDLE ColorConsole::__console_stderr_handle;

void ColorConsole::init()
{
    ColorConsole::__console_stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    ColorConsole::__console_stderr_handle = GetStdHandle(STD_ERROR_HANDLE);
}

void ColorConsole::setConsStdOutColor(int color, int bgColor)
{
    SetConsoleTextAttribute(ColorConsole::__console_stdout_handle, color + (bgColor*16));
}

void ColorConsole::setConsStdErrColor(int color, int bgColor)
{
    SetConsoleTextAttribute(ColorConsole::__console_stderr_handle, color + (bgColor*16));
}

void ColorConsole::setConsStdOutDefColor()
{
   SetConsoleTextAttribute(ColorConsole::__console_stdout_handle, 7);
}
void ColorConsole::setConsStdErrDefColor()
{
   SetConsoleTextAttribute(ColorConsole::__console_stderr_handle, 7);
}

void ColorConsole::emptyLine()
{
    ColorConsole::setConsStdErrDefColor();
    std::cout << std::endl;
}

}