/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Examples for article on blog https://blog.altuninvv.ru
**
****************************************************************************/

#include "testclass1.h"
#include <QCoreApplication>
#include <QDebug>
#include "foo.h"
#include "testclass2.h"


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() <<  doBar(42);

    qDebug() <<  doBar(Foo("33"));

    //qDebug() <<  doBar("42"); //<== error here

    qDebug() << "-------------";
    qDebug() << "Program start!";
    qDebug() << "-------------";

    TestClass1 t;

    t.setStr("12345");
    qDebug() << t.getStr();

    qDebug() << "-------------";

    for (int i=0; i< 2; i++)
       {
           qDebug() << "-------------";
           TestClass1 t1(QString::number(i));
           qDebug() << t1.getStr();
       }

    qDebug() << "=============";

    for (int i=10; i< 12; i++)
    {
        TestClass1 *t2 = new TestClass1(QString::number(i));
        qDebug() << t2->getStr();
        delete t2;
    }

    qDebug() << "=============";

    TestClass2 t3("100");
    qDebug() << t3.getStrp();


    qDebug() << "=============";

    TestClass2 t4("500");

    TestClass2 t5 = t4;

    qDebug() << t4.getStrp();
    qDebug() << t5.getStrp();

    qDebug() << "boolval=" << t4.getBoolval();
    qDebug() << "boolval=" << t5.getBoolval();

    qDebug() << "-------------";
    qDebug() << "Program end!";
    qDebug() << "-------------";



    app.quit();
}
