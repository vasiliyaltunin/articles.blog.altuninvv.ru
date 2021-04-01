/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how to show logs loaded from file into QTableView widget in Qt5
**
****************************************************************************/
#ifndef WSUSLOGRECORD_H
#define WSUSLOGRECORD_H

#include <qstring.h>



class WSUSLogRecord
{
public:
    WSUSLogRecord();

    QString getDate() const;
    void setDate(const QString &value);

    QString getEventType() const;
    void setEventType(const QString &value);

    QString getService() const;
    void setService(const QString &value);

    QString getEvent() const;
    void setEvent(const QString &value);

    QString getData() const;
    void setData(const QString &value);

    QString getId() const;
    void setId(const QString &value);

private:
    QString id;
    QString date;
    QString eventType;
    QString service;
    QString event;
    QString data;
};

QDebug operator<<(QDebug debug, const WSUSLogRecord &user);
QDebug operator<<(QDebug debug, const WSUSLogRecord *user);

#endif // WSUSLOGRECORD_H
