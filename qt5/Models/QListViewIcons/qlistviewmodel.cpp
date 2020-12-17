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

#include "qlistviewmodel.h"

#include <QModelIndex>
#include <QDebug>
#include <QPixmap>

QListViewModel::QListViewModel(QObject *parent)
    :QAbstractListModel(parent)
{
    values = new QList<CountryFlag>();
}

int QListViewModel::rowCount(const QModelIndex &) const
{
    return values->count();
}

QVariant QListViewModel::data( const QModelIndex &index, int role ) const
{

    QVariant value;

        switch ( role )
        {
            case Qt::DisplayRole: //string
            {
                value = this->values->at(index.row()).getName();
            }
            break;

            case Qt::DecorationRole: //image
            {
                QPixmap icon = QPixmap(":/img/" + this->values->value(index.row()).getIcon());
                QPixmap tmp = icon.scaled(30, 30, Qt::KeepAspectRatio);
                value = tmp;
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

void QListViewModel::populate(QList<CountryFlag> *newValues)
{
    int idx = this->values->count();
    this->beginInsertRows(QModelIndex(), 1, idx);
        this->values = newValues;
    endInsertRows();
 }

void QListViewModel::append(CountryFlag value)
{
    int newRow = this->values->count()+1;

    this->beginInsertRows(QModelIndex(), newRow, newRow);
        values->append(value);
    endInsertRows();
}

void QListViewModel::update(int idx, CountryFlag value)
{
    (*this->values)[idx] = value;

    QModelIndex item_idx = this->index(idx,0);

    emit this->dataChanged(item_idx ,item_idx );
}

void QListViewModel::deleteRow(int idx)
{
    this->beginRemoveRows(QModelIndex(), idx,idx);

        (*this->values).removeAt(idx);

    this->endRemoveRows();
}

void QListViewModel::insertAt(int idx, CountryFlag value)
{

    int newRow = idx;

    this->beginInsertRows(QModelIndex(), newRow, newRow);

        values->insert(newRow,value);

    endInsertRows();
}
