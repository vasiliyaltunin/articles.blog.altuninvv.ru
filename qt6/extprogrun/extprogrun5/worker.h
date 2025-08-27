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

#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QProcess>

class Worker: public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);

public slots:
    virtual void onRead(const QString &data);
    void onError(const QString &data);
    void onErrorFinished(const QProcess::ProcessError &errorCode);
    void onProgramFinished(const int &exitCode, const QProcess::ExitStatus &exitStatus);

};

#endif // WORKER_H
