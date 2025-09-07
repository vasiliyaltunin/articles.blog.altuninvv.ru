#include <iostream>
#include "../../src/colorconsole.h"

using ccon::ColorConsole;

int main(int argc, char *argv[])
{
   ColorConsole::init();
   
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
   
   ColorConsole::setConsStdOutDefColor();
   return 0;
}