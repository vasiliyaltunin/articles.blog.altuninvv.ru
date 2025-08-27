/****************************************************************************
**
** Copyright 2025 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Qt6 Thread Readline worker class
**
****************************************************************************/

#include "readlineworker.h"

ReadLineWorker::ReadLineWorker(QObject *parent)
{
    this->parser = new RegexParser("(.[^\\r\\n]*)(?:\\n|\\r\\n)?");

    QObject::connect(this->parser, SIGNAL(matched(QString)),
                     this, SLOT(onStringRead(QString)));

}

void ReadLineWorker::onRead(const QString &data)
{
    this->parser->parseAll(data);

    //     qDebug() << "Worker:" << data;
}

void ReadLineWorker::onStringRead(QString data)
{
    emit stringRead(data);
}
