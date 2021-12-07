/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** QSerialIO - read and write bytes from serial (COM) port
**
****************************************************************************/

#include "qserialio.h"
#include <QDebug>

QSerialIO::QSerialIO(QSerialPort *serialPort, QObject *parent) :
    QObject(parent)
{
    this->serialPort = serialPort;
     connect(serialPort, SIGNAL(readyRead()), this, SLOT(handleRead()));
     connect(serialPort, SIGNAL(errorOccurred(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));

}

void QSerialIO::handleRead()
{
    QByteArray d = serialPort->readAll();
    QString ds = d;
    qDebug() << d << ds.simplified();
}

void QSerialIO::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        qDebug() << "I/O error on port" << serialPort->portName() << serialPort->errorString();
    }
}
