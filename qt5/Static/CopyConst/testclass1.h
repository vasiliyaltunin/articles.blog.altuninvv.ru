/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Constructor example class for article on blog https://blog.altuninvv.ru
**
****************************************************************************/

#ifndef TESTCLASS1_H
#define TESTCLASS1_H

#include <QString>

class TestClass1
{
public:
    explicit TestClass1();
    explicit TestClass1(const QString &value);

    ~TestClass1();


    QString getStr() const;
    void setStr(const QString &value);

private:
    QString str;
};

#endif // TESTCLASS1_H
