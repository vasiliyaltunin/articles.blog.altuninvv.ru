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


#include <QGuiApplication>
#include <QProcess>
#include <QQmlApplicationEngine>
#include <QThread>

#include "runner.h"

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

    QThread thread;
    thread.setObjectName("Runner thread");
    Runner r;

    QObject::connect(&thread, &QThread::started, &r, &Runner::run);
    QObject::connect(&r, &Runner::finished, &thread, &QThread::terminate);

    r.moveToThread(&thread);
    thread.start();

    return app.exec();
}
