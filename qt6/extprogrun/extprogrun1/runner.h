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


#ifndef RUNNER_H
#define RUNNER_H

#include <QObject>
#include <QProcess>

class Runner  : public QObject
{
    Q_OBJECT

signals:
    void finished();

public:
    Runner();

    void run();



private:
    QProcess *process;
};

#endif // RUNNER_H
