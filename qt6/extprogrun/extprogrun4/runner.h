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
    void errorFinished(QProcess::ProcessError errorCode);
    void programFinished(int exitCode, QProcess::ExitStatus exitStatus);

public:
    Runner();

    void run();

    bool getCodecUsed() const;
    void codecUsed(bool newIsCodec);

    QString getCodecName() const;
    void setCodecName(const QString &newCodecName);

    QString getProgram() const;
    void setProgram(const QString &newProgram);

    QStringList getParams() const;
    void setParams(const QStringList &newParams);

private slots:
    void onReady();
    void onError();
    void onFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void onProcessError(QProcess::ProcessError errorCode);

private:
    QProcess *process;
    QTextCodec *codec;
    bool isCodec = false;
    QString codecName;
    QString program;
    QStringList params;

};

#endif // RUNNER_H
