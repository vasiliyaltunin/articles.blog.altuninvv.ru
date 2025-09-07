#include <iostream>
#include <string>
#include <random>

#include "../../src/colorconsole.h"

using ccon::ColorConsole;

int main(int argc, char *argv[])
{
    ColorConsole::init();

    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distr(0, 15);

    std::string str = "ColorConsole";

    for (int i = 0; i <= str.length()-1; i++)
    {
       ColorConsole::setConsStdOutColor(distr(gen),distr(gen));
        std::cout << str[i];       
    }   

    ColorConsole::setConsStdOutDefColor();

    return 0;
}