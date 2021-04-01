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
#include "qtableviewmodel.h"

#include <QModelIndex>
#include <QDebug>
#include <QPixmap>

QTableViewModel::QTableViewModel(QObject *parent)
    :QAbstractListModel(parent)
{
    values = new QList<WSUSLogRecord>();
}

int QTableViewModel::rowCount(const QModelIndex &) const
{
    return values->count();
}

int QTableViewModel::columnCount(const QModelIndex &) const
{
    return 5;
}

QVariant QTableViewModel::data( const QModelIndex &index, int role ) const
{

    QVariant value;

        switch ( role )
        {
            case Qt::DisplayRole: //string
            {
                switch (index.column()) {
                    case 0: {
                        value = this->values->at(index.row()).getDate();
                        break;
                    }
                    case 1: {
                        value = this->values->at(index.row()).getEventType();
                        break;
                    }
                    case 2: {
                        value = this->values->at(index.row()).getService();
                        break;
                    }
                    case 3: {
                        value = this->values->at(index.row()).getEvent();
                        break;
                    }
                    case 4: {
                        value = this->values->at(index.row()).getData().replace("\n", " ");
                        break;
                    }
                }
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

QVariant QTableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return QString("Date");
        case 1:
            return QString("Type");
        case 2:
            return QString("Service");
        case 3:
            return QString("Event");
        case 4:
            return QString("Datas");
        }
    }
    return QVariant();
}

void QTableViewModel::populate(QList<WSUSLogRecord> *newValues)
{
    int idx = this->values->count();
    this->beginInsertRows(QModelIndex(), 1, idx);
        this->values = newValues;
    endInsertRows();
 }

void QTableViewModel::append( const WSUSLogRecord &value)
{
    int newRow = this->values->count()+1;

    this->beginInsertRows(QModelIndex(), newRow, newRow);
        values->append(value);
    endInsertRows();
}

void QTableViewModel::update(int idx, const WSUSLogRecord &value)
{
    (*this->values)[idx] = value;

    QModelIndex item_idx_s = this->index(idx,0);
    QModelIndex item_idx_e = this->index(idx,this->columnCount(QModelIndex()));

    emit this->dataChanged(item_idx_s ,item_idx_e );
}

void QTableViewModel::deleteRow(int idx)
{
    this->beginRemoveRows(QModelIndex(), idx,idx);

        (*this->values).removeAt(idx);

    this->endRemoveRows();
}

void QTableViewModel::insertAt(int idx, const WSUSLogRecord &value)
{

    int newRow = idx;

    this->beginInsertRows(QModelIndex(), newRow, newRow);

        values->insert(newRow,value);

    endInsertRows();
}
