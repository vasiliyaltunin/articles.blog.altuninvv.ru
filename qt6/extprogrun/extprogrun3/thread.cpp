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

#include "thread.h"

Thread::Thread(const QString program, QStringList params, Runner *runner) {
    this->thread = new QThread();
    this->thread->setObjectName("Runner thread");

    this->runner = runner;
    this->program = program;
    this->params = params;

    this->runner->codecUsed(true);

    this->runner->setProgram(this->program);
    this->runner->setParams(this->params);

    QObject::connect(this->thread, QThread::started, this->runner, Runner::run);
    QObject::connect(this->runner, Runner::finished, this->thread, QThread::terminate);

    this->runner->moveToThread(thread);
}

void Thread::start()
{
    this->thread->start();
}
