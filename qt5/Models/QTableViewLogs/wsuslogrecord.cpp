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
#include "wsuslogrecord.h"

#include <QDebugStateSaver>

WSUSLogRecord::WSUSLogRecord()
{

}

QString WSUSLogRecord::getDate() const
{
    return date;
}

void WSUSLogRecord::setDate(const QString &value)
{
    date = value;
}

QString WSUSLogRecord::getEventType() const
{
    return eventType;
}

void WSUSLogRecord::setEventType(const QString &value)
{
    eventType = value;
}

QString WSUSLogRecord::getService() const
{
    return service;
}

void WSUSLogRecord::setService(const QString &value)
{
    service = value;
}

QString WSUSLogRecord::getEvent() const
{
    return event;
}

void WSUSLogRecord::setEvent(const QString &value)
{
    event = value;
}

QString WSUSLogRecord::getData() const
{
    return data;
}

void WSUSLogRecord::setData(const QString &value)
{
    data = value;
}

QString WSUSLogRecord::getId() const
{
    return id;
}

void WSUSLogRecord::setId(const QString &value)
{
    id = value;
}

QDebug operator<<(QDebug debug, const WSUSLogRecord &rec)
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "WSUSLogRecord( "
        << "Id: " << rec.getId() << ", "
        << "Date: " << rec.getDate() << ", "
        << "Event type: " << rec.getEventType() << ", "
        << "Service: " << rec.getService() << ", "
        << "Event: " << rec.getEvent() << ", "
        << "Datas: " << rec.getData() << ""
        << " )";

    return debug;
}


QDebug operator<<(QDebug debug, const WSUSLogRecord *rec)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << *rec;
    return debug;
}
