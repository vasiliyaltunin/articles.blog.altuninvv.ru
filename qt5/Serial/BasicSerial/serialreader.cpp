#include "serialreader.h"
#include <QDataStream>
#include <QDebug>

SerialReader::SerialReader(QSerialPort *serialPort, QObject *parent) :
    QObject(parent)
{    
    this->serialPort = serialPort;
     connect(serialPort, SIGNAL(readyRead()), this, SLOT(handleRead()));
     connect(serialPort, SIGNAL(errorOccurred(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));

//     qDebug() << "Init ok";

//     m_timer = new QTimer(parent);

//     connect(m_timer, SIGNAL(timeout()), this, SLOT(handleTimeout()));

//     m_timer->start(5000);
}

void SerialReader::handleRead()
{
    QByteArray d = serialPort->readAll();
    qDebug() << d;
    data.append(d);
    //int v = d.toInt();
    //qDebug() << v;

    if (data.count() > 2) {
        qDebug() << "1" << data;
    }


}

/*
void SerialReader::handleTimeout()
{
    if (data.isEmpty()) {
        //qDebug() << "No data in " << serialPort->portName();
    }
}
*/
void SerialReader::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        qDebug() << "I/O error on port %1" << serialPort->portName() << serialPort->errorString();
    }
}
