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

#ifndef QSERIALIO_H
#define QSERIALIO_H

#include <QSerialPort>

class QSerialIO : public QObject
{
    Q_OBJECT
public:
    explicit QSerialIO(QSerialPort *serialPort, QObject *parent = nullptr);

public slots:
    void handleRead();
    void handleError(QSerialPort::SerialPortError serialPortError);
private:
  QByteArray data;
  QSerialPort *serialPort = nullptr;
};

#endif // QSERIALIO_H
