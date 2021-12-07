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

#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include <QSerialPort>


class SerialPortManager
{
public:
    SerialPortManager(QString portName,
                        qint32 baud = QSerialPort::Baud9600,
                        QSerialPort::DataBits bits = QSerialPort::Data8,
                        QSerialPort::StopBits sbits = QSerialPort::OneStop,
                        QSerialPort::Parity parity = QSerialPort::NoParity,
                        QSerialPort::FlowControl flow = QSerialPort::NoFlowControl);
    ~SerialPortManager();

    QSerialPort *getSerialPort() const;

private:
    QSerialPort *serialPort;
    QString portName;
};

#endif // SERIALPORTMANAGER_H
