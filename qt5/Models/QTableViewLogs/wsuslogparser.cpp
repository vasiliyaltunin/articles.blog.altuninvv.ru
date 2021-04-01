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
#include "wsuslogparser.h"

#include <QFile>
#include <QDebug>
#include <QRegularExpression>
#include <cstdlib>


WSUSLogParser::WSUSLogParser(QList<WSUSLogRecord> *values)
{
    this->values = values;
}

void WSUSLogParser::Load(QString fileName)
{

    int id=0;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open input file.";
        exit(-1);
    }

    QRegularExpression re("^([0-9\\w\\-:. ]+)\\t(\\w+)\\t([\\w+.0-9]+)\\t([\\w+.0-9]+)\\t(.*)");

    WSUSLogRecord currentRecord;

    while (!file.atEnd())
    {
        QString line = file.readLine();
        QRegularExpressionMatch match = re.match(line);


        if (match.hasMatch()) {
            if (!currentRecord.getDate().isEmpty())
            {
               values->append(currentRecord);
            }

            currentRecord = WSUSLogRecord();

            currentRecord.setId(QString::number(id));
            id++;
            currentRecord.setDate(match.captured(1));
            currentRecord.setEventType(match.captured(2));
            currentRecord.setService(match.captured(3));
            currentRecord.setEvent(match.captured(4));
            currentRecord.setData(match.captured(5));

        } else {
            QString tmp = currentRecord.getData();
            tmp  = tmp + line;
            currentRecord.setData(tmp);
        }



    }
    qDebug() << values->at(0);

}
