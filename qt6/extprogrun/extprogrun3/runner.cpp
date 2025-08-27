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

    this->codecName = "IBM 866";

    this->codec = QTextCodec::codecForName(this->codecName.toLatin1().data());

    connect(this->process, SIGNAL(readyReadStandardOutput()),
            this, SLOT(onReady()));
    connect(this->process, SIGNAL(readyReadStandardError()),
            this, SLOT(onError()));
    connect(this->process, SIGNAL(finished(int,QProcess::ExitStatus)),
            this, SLOT(onFinished(int,QProcess::ExitStatus)));
    qDebug() << "Инит";
}

void Runner::run()
{
    qDebug() << "Запуск";
    this->process->start(this->program, this->params);
    qDebug() << "Запущено";
}

void Runner::onReady()
{
    QString res;

    if (this->isCodec == true) {
        res = this->codec->toUnicode(this->process->readAllStandardOutput());
    } else {
        res = this->process->readAllStandardOutput();
    }

    qDebug() << "Результат:" << res;

    emit ready(res);
}

void Runner::onError()
{
    QString res;

    if (this->isCodec == true) {
        res = this->codec->toUnicode(this->process->readAllStandardError());
    } else {
        res = this->process->readAllStandardError();
    }

    qDebug() << "Ошибка:" << res;

    emit error(res);
}


void Runner::onFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "Код завершения" << exitCode;
    qDebug() << "Статус выхода" << exitStatus;
}

bool Runner::getCodecUsed() const
{
    return isCodec;
}

void Runner::codecUsed(bool newIsCodec)
{
    isCodec = newIsCodec;
}

QString Runner::getCodecName() const
{
    return codecName;
}

void Runner::setCodecName(const QString &newCodecName)
{
    codecName = newCodecName;
    this->codec = QTextCodec::codecForName(this->codecName.toLatin1().data());
}

QString Runner::getProgram() const
{
    return program;
}

void Runner::setProgram(const QString &newProgram)
{
    program = newProgram;
}

QStringList Runner::getParams() const
{
    return params;
}

void Runner::setParams(const QStringList &newParams)
{
    params = newParams;
}
