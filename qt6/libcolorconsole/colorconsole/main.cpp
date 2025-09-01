/****************************************************************************
**
** Copyright 2025 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Проект демонстирующий применение API Windows для вывода цветного текста 
** в консоль Windows.
**
****************************************************************************/

#include <iostream>

#include "colorconsole/colorconsole.h"

int main(int argc, char *argv[])
{
    ColorConsole::init();
    ColorConsole::setConsStdOutColor(4);
    std::cout << "Hello world";

    ColorConsole::setConsStdOutDefColor();

    std::cout << ColorConsole::__console_stdout_handle << "\n";
    std::cout << ColorConsole::__console_stderr_handle << "\n";


    

    ColorConsole::setConsStdOutColor(ColorConsole::DARK_GREEN);
    std::cout << "-== stdout ==-\n";
    
    ColorConsole::setConsStdErrColor(ColorConsole::DARK_RED);
    std::cerr << "-== !error! ==-\n";

    ColorConsole::setConsStdOutDefColor();

    ColorConsole::emptyLine(); 

    for (int i = 0; i < 256; i++)

    {
        if ((i % 16 == 0) && (i != 0)) {

            ColorConsole::emptyLine();
        }
        ColorConsole::setConsStdOutColor(i);
        printf("[%03d]",i);
    }

    ColorConsole::emptyLine();

    ColorConsole::emptyLine();
    ColorConsole::emptyLine();

    ColorConsole::setConsStdOutColor(222);

    std::cout << "[ 222 ]";
   
    ColorConsole::emptyLine();
    ColorConsole::emptyLine();

    ColorConsole::emptyLine();
    ColorConsole::emptyLine();

    ColorConsole::setConsStdOutColor(ColorConsole::WHITE,ColorConsole::WHITE);
    printf("%10s"," ");   
    ColorConsole::emptyLine();

    ColorConsole::setConsStdOutColor(ColorConsole::WHITE,ColorConsole::DARK_BLUE);
	printf("%10s","  RUSSIA  ");
    ColorConsole::emptyLine();

    ColorConsole::setConsStdOutColor(ColorConsole::DARK_RED,ColorConsole::DARK_RED);
    printf("%10s"," ");
    ColorConsole::emptyLine();
    
    ColorConsole::emptyLine();

    return 0;
}