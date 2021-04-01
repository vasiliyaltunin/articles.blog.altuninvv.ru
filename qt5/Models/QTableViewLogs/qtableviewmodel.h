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
#ifndef QTABLEVIEWMODEL_H
#define QTABLEVIEWMODEL_H


#include "wsuslogrecord.h"
#include <QModelIndex>

class QTableViewModel : public QAbstractListModel
{
public:
    QTableViewModel(QObject *parent=nullptr);
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void populate(QList<WSUSLogRecord> *newValues);

    void append( const WSUSLogRecord &value);
    void update(int idx, const WSUSLogRecord &value);
    void deleteRow(int idx);
    void insertAt(int idx, const WSUSLogRecord &value);

private:
    QList<WSUSLogRecord> *values;
};

#endif // QTABLEVIEWMODEL_H
