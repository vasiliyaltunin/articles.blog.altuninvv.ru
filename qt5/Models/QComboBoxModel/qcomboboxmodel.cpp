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

#include "qcomboboxmodel.h"

#include <QModelIndex>
#include <QDebug>

QComboBoxModel::QComboBoxModel(QObject *parent)
    :QAbstractListModel(parent)
{
    values = new QList<QPair<int,QString>>();
}

int QComboBoxModel::rowCount(const QModelIndex &) const
{
    return values->count();
}

QVariant QComboBoxModel::data( const QModelIndex &index, int role ) const
{

    QVariant value;

        switch ( role )
        {
            case Qt::DisplayRole: //string
            {
                value = this->values->value(index.row()).second;
            }
            break;

            case Qt::UserRole: //data
            {
            value = this->values->value(index.row()).first;
            }
            break;

            default:
                break;
        }

    return value;
}

void QComboBoxModel::populate(QList<QPair<int,QString>> *newValues)
{
    int idx = this->values->count();
    this->beginInsertRows(QModelIndex(), 1, idx);
        this->values = newValues;
    endInsertRows();
 }

void QComboBoxModel::append(int index, QString value)
{
    int newRow = this->values->count()+1;

    this->beginInsertRows(QModelIndex(), newRow, newRow);
        values->append(QPair<int,QString>(index,value));
    endInsertRows();
}

void QComboBoxModel::update(int idx, QString value)
{
    (*this->values)[idx].second = value;

    QModelIndex item_idx = this->index(idx,0);

    emit this->dataChanged(item_idx ,item_idx );
}

void QComboBoxModel::deleteRow(int idx)
{
    int rowIdx = this->values->count()+1;

    this->beginRemoveRows(QModelIndex(), idx,idx);

        (*this->values).removeAt(idx);

    this->endRemoveRows();
}

void QComboBoxModel::insertAt(int idx, int data_idx, QString value)
{

    int newRow = idx;

    this->beginInsertRows(QModelIndex(), newRow, newRow);

        values->insert(0,QPair<int,QString>(data_idx, value));

    endInsertRows();
}
