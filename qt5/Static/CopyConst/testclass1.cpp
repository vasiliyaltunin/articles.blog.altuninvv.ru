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

#include "testclass1.h"
#include <QDebug>

#define TEST_DEEBUG 0

TestClass1::TestClass1()
{
#ifdef TEST_DEEBUG
    qDebug() << "Created epmty TestClass1!";
#endif
}

TestClass1::~TestClass1()
{
#ifdef TEST_DEEBUG
    qDebug() << "Begin destroying TestClass1 with value: " << this->str << "...";
#endif

#ifdef TEST_DEEBUG
    qDebug() << "TestClass1 destroyed!";
#endif
}

TestClass1::TestClass1(const QString &value)
{
#ifdef TEST_DEEBUG
    qDebug() << "Created TestClass1 with value:" << value;
#endif
    this->str = value;
}

QString TestClass1::getStr() const
{
#ifdef TEST_DEEBUG
    qDebug() << "TestClass1 string get: " << this->str;
#endif
    return this->str;
}

void TestClass1::setStr(const QString &value)
{
#ifdef TEST_DEEBUG
    qDebug() << "TestClass1 string set: " << value;
#endif
    this->str = value;
}
