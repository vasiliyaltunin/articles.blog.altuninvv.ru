/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how to use model with QComboBox widget in Qt5
**
****************************************************************************/

#ifndef QCOMBOBOXMODEL_H
#define QCOMBOBOXMODEL_H

#include "countryflag.h"

#include <QModelIndex>

class QComboBoxModel : public QAbstractListModel
{
public:
    QComboBoxModel(QObject *parent=nullptr);
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    void populate(QList<CountryFlag> *newValues);
    void append(CountryFlag value);
    void update(int idx, CountryFlag value);
    void deleteRow(int idx);
    void insertAt(int idx, CountryFlag value);
private:
    QList<CountryFlag> *values;
};

#endif // QCOMBOBOXMODEL_H
