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

#ifndef READLINEWORKER_H
#define READLINEWORKER_H

#include <QObject>

#include "worker.h"
#include "regexparser.h"

class ReadLineWorker: public Worker
{
    Q_OBJECT
public:
    explicit ReadLineWorker(QObject *parent = 0);

    virtual void onRead(const QString &data);

signals:
    void stringRead(QString data);

private:
    RegexParser *parser;

public slots:
    void onStringRead(QString data);
};

#endif // READLINEWORKER_H
