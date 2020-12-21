/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how to extend model with class to use with model with QTableView widget in Qt5
**
****************************************************************************/

#ifndef QTABLEVIEWMODEL_H
#define QTABLEVIEWMODEL_H


#include "countryflag.h"
#include <QModelIndex>

class QTableViewModel : public QAbstractListModel
{
public:
    QTableViewModel(QObject *parent=nullptr);
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void populate(QList<CountryFlag> *newValues);

    void append(CountryFlag value);
    void update(int idx, CountryFlag value);
    void deleteRow(int idx);
    void insertAt(int idx, CountryFlag value);

private:
    QList<CountryFlag> *values;
};

#endif // QTABLEVIEWMODEL_H
