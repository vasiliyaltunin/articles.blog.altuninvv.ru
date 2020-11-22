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

#include <QModelIndex>

class QComboBoxModel : public QAbstractListModel
{
public:
    QComboBoxModel(QObject *parent=nullptr);
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    void populate(QList<QPair<int, QString> > *newValues);
    void append(int index, QString value);
    void update(int idx, QString value);
    void deleteRow(int idx);
    void insertAt(int idx, int data_idx, QString value);
private:
    QList<QPair<int,QString>> *values;
};

#endif // QCOMBOBOXMODEL_H
