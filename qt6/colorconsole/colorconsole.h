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

#ifndef COLORCONSOLE_H
#define COLORCONSOLE_H

#include <windows.h>

class ColorConsole 
{

public:
    static const int  BLACK         =  0;
    static const int  DARK_BLUE     =  1;
    static const int  DARK_GREEN    =  2;
    static const int  DARK_CYAN     =  3;
    static const int  DARK_RED      =  4;
    static const int  DARK_MAGENTA  =  5;
    static const int  DARK_YELLOW   =  6;
    static const int  LIGHT_GRAY    =  7;
    static const int  DARK_GRAY     =  8;
    static const int  LIGHT_BLUE    =  9;
    static const int  LIGHT_GREEN   = 10;
    static const int  LIGHT_CYAN    = 11;
    static const int  LIGHT_RED     = 12;
    static const int  LIGHT_MAGENTA = 13;
    static const int  LIGHT_YELLOW  = 14;
    static const int  WHITE         = 15;

    ColorConsole();
    ~ColorConsole();

    static void init();
    
    static HANDLE __console_stdout_handle;
    static HANDLE __console_stderr_handle;

    static void setConsStdOutColor(int color, int bgColor = 0);
    static void setConsStdErrColor(int color, int bgColor = 0);    

    static void setConsStdOutDefColor();
    static void setConsStdErrDefColor();

    static void emptyLine();
};

#endif