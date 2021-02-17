#ifndef QSTR_H
#define QSTR_H

#include <QString>



class QStr
{
public:
    QStr();
    static char *qStringToChar(const QString &value);
    static void qStringToChar1(const QString &value, char* cstring);
};

#endif // QSTR_H
