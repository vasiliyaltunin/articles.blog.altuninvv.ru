#include "qstr.h"

QStr::QStr()
{

}

char* QStr::qStringToChar(const QString &value)
{
    //std::string tmp;

    QByteArray ba = value.toLatin1();
    char *tmp = new char[value.length()];
    //tmp = value.toStdString();
    //tmp = new char[value.length()];
    //tmp = ba.data();
    //tmpc = tmp.c
    strcpy(tmp, ba.data());
    return tmp;
}

