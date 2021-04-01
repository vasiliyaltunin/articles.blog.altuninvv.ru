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
#ifndef WSUSLOGPARSER_H
#define WSUSLOGPARSER_H

#include "wsuslogrecord.h"



class WSUSLogParser
{
public:
    explicit WSUSLogParser(QList<WSUSLogRecord> *values);
    void Load(QString fileName);
    QList<WSUSLogRecord> *values;
};

#endif // WSUSLOGPARSER_H
