/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how to create delegate to use with QTableView widget in Qt5
**
****************************************************************************/

#include "tableitemdelegate.h"
#include "math.h"

#include <QPainter>
#include <QDebug>


TableItemDelegate::TableItemDelegate()
{

}

QSize TableItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QItemDelegate::sizeHint(option, index);
}

void TableItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem myOption = option;

    if (index.column()==2)
    {
        QString data = index.model()->data(index, Qt::DisplayRole).toString();


        myOption.displayAlignment = Qt::AlignCenter | Qt::AlignVCenter;

        QString icon = ":/img/" + index.model()->data(index, Qt::DisplayRole).toString();

        qDebug() << icon;

        QPixmap pixmap2(icon);

        painter->drawPixmap(myOption.rect.x()+30,myOption.rect.y(),32,32, pixmap2);
    }
    else
    {
        drawDisplay(painter, option, option.rect, index.model()->data(index, Qt::DisplayRole).toString());

    }
    drawFocus(painter, myOption, myOption.rect);

}
