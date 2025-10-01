#include <iostream>

#include "colorconsole/colorconsole.h"

using ccon::ColorConsole;

int main(int argc, char *argv[])
{
   ColorConsole::init();

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

    return 0;
}