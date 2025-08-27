/****************************************************************************
**
** Copyright 2025 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Qt6 Thread work class
**
****************************************************************************/


#ifndef THREAD_H
#define THREAD_H

#include <QThread>

#include "runner.h"

class Thread : public QObject
{
    Q_OBJECT
public:
    Thread(QString program, QStringList params, Runner *runner);
    void start();
private:
    QThread *thread;
    Runner *runner;
    QString program;
    QStringList params;
};

#endif // THREAD_H
