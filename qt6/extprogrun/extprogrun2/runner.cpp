/****************************************************************************
**
** Copyright 2025 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Qt6 Thread Runner class
**
****************************************************************************/


#include "runner.h"
#include <QDebug>

Runner::Runner() {

    this->process = new QProcess(this);
    qDebug() << "Инит";

    this->codec = QTextCodec::codecForName("IBM 866");

    connect(this->process, SIGNAL(readyReadStandardOutput()),
            this, SLOT(onReady()));
    connect(this->process, SIGNAL(readyReadStandardError()),
            this, SLOT(onError()));
    connect(this->process, SIGNAL(finished(int,QProcess::ExitStatus)),
            this, SLOT(onFinished(int,QProcess::ExitStatus)));

}

void Runner::run()
{
    QStringList params;
    params.append("/C command.cmd");
    qDebug() << "Запуск";
    this->process->start("cmd", params);
    qDebug() << "Запущено";

    emit finished();
}

void Runner::onReady()
{
    QString res = this->codec->toUnicode(this->process->readAllStandardOutput());

    qDebug() << "Результат:" << res;
    emit ready(res);
}

void Runner::onError()
{
    QString res = this->codec->toUnicode(this->process->readAllStandardError());

    qDebug() << "Результат:" << res;
    emit error(res);
}

void Runner::onFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "Код завершения" << exitCode;
    qDebug() << "Статус выхода" << exitStatus;
}
