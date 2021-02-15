/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Copy constructor example class for article on blog https://blog.altuninvv.ru
**
****************************************************************************/
#ifndef TESTCLASS2_H
#define TESTCLASS2_H

#include "testclass1.h"

class TestClass2 //: public TestClass1
{
public:
    explicit TestClass2();
    explicit TestClass2(const QString &value);
    TestClass2(const TestClass2 &old, const int boolval=1);

    ~TestClass2();

    char* getStrp() const;
    void setStrp(const QString);

    int getBoolval() const;
    void setBoolval(int value);

private:
    char *strp;

    int boolval;

};

#endif // TESTCLASS2_H
