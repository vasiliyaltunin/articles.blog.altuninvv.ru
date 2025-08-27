/****************************************************************************
**
** Copyright 2025 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Qt6 Thread worker class
**
****************************************************************************/

#include "worker.h"
#include <QDebug>

Worker::Worker(QObject *parent) :
    QObject(parent)
{
}

void Worker::onRead(const QString &data)
{
    qDebug() << "Worker:" << data;
}

void Worker::onError(const QString &data)
{
    qDebug() << "Worker error:" << data;
}

void Worker::onErrorFinished(const QProcess::ProcessError &errorCode)
{
    qDebug() << "Worker: Внешняя программа завершилась с кодом ошибки:" << errorCode;
}

void Worker::onProgramFinished(const int &exitCode, const QProcess::ExitStatus &exitStatus)
{
    qDebug() << "Worker: Внешняя программа успешно завершилась с кодом:" << exitCode << "и статусом " << exitStatus;
}
