/****************************************************************************
**
** Copyright 2025 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Qt6 Thread Runner demo
**
****************************************************************************/

#include "thread.h"
#include "dirsizeworker.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("extprogrun1", "Main");

    QStringList params;
    params.append("/C command.cmd");

    Thread *t = new Thread("cmd", params, new Runner(), new DirSizeWorker());
    t->start();

    return app.exec();
}
