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
#include "testclass2.h"
#include <QDebug>

#define TEST_DEEBUG 0

TestClass2::TestClass2()
{
#ifdef TEST_DEEBUG
    qDebug() << "Created TestClass2!";
#endif
    this->strp = NULL;
}

TestClass2::~TestClass2()
{
#ifdef TEST_DEEBUG
    qDebug() << "Begin destroying TestClass2 with value: " << QString(this->strp) << "...";
#endif
    delete[] this->strp;

#ifdef TEST_DEEBUG
    qDebug() << "TestClass2 destroyed!";
#endif
}

TestClass2::TestClass2(const QString &value)
{
#ifdef TEST_DEEBUG
    qDebug() << "Created TestClass2 width value " << value;
    qDebug() << "Boolval = " << this->boolval;
#endif
    this->strp = new char[value.length()+1];
    strcpy(this->strp,(char*)value.toStdString().c_str());
}

TestClass2::TestClass2(const TestClass2 &old, const int boolval)
{
#ifdef TEST_DEEBUG
    qDebug() << "Copy contructor called with old value " << old.getStrp();
    qDebug() << "Copy contructor sets boolval = " << boolval;
#endif

    int size = sizeof(*old.getStrp()) / sizeof(char);

    this->strp = new char[size+1];
    strcpy(this->strp,old.getStrp());

    this->boolval = boolval;
}


char* TestClass2::getStrp() const
{
#ifdef TEST_DEEBUG
    qDebug() << "TestClass2 pointer get: " << this->strp;
#endif

    return strp;
}

void TestClass2::setStrp(const QString value)
{
#ifdef TEST_DEEBUG
    qDebug() << "TestClass2  pointer set: " << value << "prev val: " << this->strp;
#endif
    delete[] this->strp;
    this->strp = new char[value.length()+1];
    strcpy(this->strp,(char*)value.toStdString().c_str());
}

int TestClass2::getBoolval() const
{
    return boolval;
}

void TestClass2::setBoolval(int value)
{
    boolval = value;
}
