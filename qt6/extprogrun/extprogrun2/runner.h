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
#include <QTextCodec>

class Runner  : public QObject
{
    Q_OBJECT

signals:
    void finished();
    void error(QString data);
    void ready(QString data);

public:
    Runner();

    void run();

private slots:
    void onReady();
    void onError();
    void onFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    QProcess *process;
    QTextCodec *codec;

};

#endif // RUNNER_H
