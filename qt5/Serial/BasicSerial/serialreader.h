#ifndef SERIALREADER_H
#define SERIALREADER_H

#include <QSerialPort>
#include <QTimer>

class SerialReader : public QObject
{
    Q_OBJECT
public:
    explicit SerialReader(QSerialPort *serialPort, QObject *parent = nullptr);

public slots:
    void handleRead();
    void handleError(QSerialPort::SerialPortError serialPortError);

    //void handleTimeout();
private:
  QByteArray data;
  QSerialPort *serialPort = nullptr;
};

#endif // SERIALREADER_H
