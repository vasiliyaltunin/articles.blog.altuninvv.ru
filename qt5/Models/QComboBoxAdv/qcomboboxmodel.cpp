/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how to extend model with class to use with model with QComboBox widget in Qt5
**
****************************************************************************/

#include "qcomboboxmodel.h"

#include <QModelIndex>
#include <QDebug>

QComboBoxModel::QComboBoxModel(QObject *parent)
    :QAbstractListModel(parent)
{
    values = new QList<CountryFlag>();
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
                value = this->values->at(index.row()).getName() + " - " + this->values->at(index.row()).getCapital();
            }
            break;

            case Qt::UserRole: //data            
            {
                value = this->values->at(index.row()).getId();
            }
            break;

            default:
                break;
        }

    return value;
}

void QComboBoxModel::populate(QList<CountryFlag> *newValues)
{
    int idx = this->values->count();
    this->beginInsertRows(QModelIndex(), 1, idx);
        this->values = newValues;
    endInsertRows();
 }

void QComboBoxModel::append(CountryFlag value)
{
    int newRow = this->values->count()+1;

    this->beginInsertRows(QModelIndex(), newRow, newRow);
        values->append(value);
    endInsertRows();
}

void QComboBoxModel::update(int idx, CountryFlag value)
{
    (*this->values)[idx] = value;

    QModelIndex item_idx = this->index(idx,0);

    emit this->dataChanged(item_idx ,item_idx );
}

void QComboBoxModel::deleteRow(int idx)
{
    this->beginRemoveRows(QModelIndex(), idx,idx);

        (*this->values).removeAt(idx);

    this->endRemoveRows();
}

void QComboBoxModel::insertAt(int idx, CountryFlag value)
{

    int newRow = idx;

    this->beginInsertRows(QModelIndex(), newRow, newRow);

        values->insert(newRow,value);

    endInsertRows();
}
