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

}

void Runner::run()
{
    QStringList params;
    qDebug() << "Запуск";
    this->process->start("command.cmd", params);
    qDebug() << "Запущено";

    this->process->waitForFinished();

    QString res = this->process->readAllStandardOutput();
    qDebug() << "Результат:" << res;

    emit finished();
}
