/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** SerialPortManager - helper class to make connects to the serial (COM)
** port and connection settings easy.
**
****************************************************************************/


#include "serialportmanager.h"
#include <QDebug>

SerialPortManager::SerialPortManager(QString portName,
                                     qint32 baud,
                                     QSerialPort::DataBits bits,
                                     QSerialPort::StopBits sbits,
                                     QSerialPort::Parity parity,
                                     QSerialPort::FlowControl flow)
{
    this->serialPort = new QSerialPort();

    this->portName = portName;

    this->serialPort->setPortName(portName);
    this->serialPort->setBaudRate(baud);
    this->serialPort->setDataBits(bits);
    this->serialPort->setStopBits(sbits);
    this->serialPort->setParity(parity);
    this->serialPort->setFlowControl(flow);


    bool result = this->serialPort->open(QIODevice::ReadOnly);

    if (!result) {
        qDebug() << "Failed to open port: " << this->portName << ", error: " << this->serialPort->errorString();
    } else {
        qDebug() << "Connected to " << this->portName;
    }


}

SerialPortManager::~SerialPortManager()
{
    this->serialPort->close();
}

QSerialPort *SerialPortManager::getSerialPort() const
{
    return this->serialPort;
}
