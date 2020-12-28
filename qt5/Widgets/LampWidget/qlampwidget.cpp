/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Simple widget - lamp.
**
****************************************************************************/

#include "qlampwidget.h"

#include <QPainter>
#include <QPen>

void QLampWidget::paintEvent(QPaintEvent *event)
{
    QString onColor = this->color;
    QColor mainColorOn = QColor(onColor);
    QColor subColorOn = QColor(onColor);
    subColorOn.setHsl(0,100,95,0);


    QString offColor = "#808080";
    QColor mainColorOff = QColor(offColor);
    QColor subColorOff = QColor(offColor);
    subColorOff.setHsl(0,100,95,0);

    QLinearGradient linearGrad(QPointF(4, 4), QPointF(28, 28));

    if (this->getStatus()==QLampWidget::on)
    {
        linearGrad.setColorAt(0, subColorOn);
        linearGrad.setColorAt(1, mainColorOn);
    } else  {
        linearGrad.setColorAt(0, subColorOff);
        linearGrad.setColorAt(1, mainColorOff);
    }


    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QPen(QColor("#f00"), 0.1));
    painter.setBrush(linearGrad);

    painter.drawEllipse(QRectF(4,4,24,24));

    /*painter.setBrush(QColor(Qt::transparent));
    painter.setPen(QPen(QColor("#00f"), 1));
    painter.drawRect(0,0,this->rect().width(),this->rect().height());
    */

}

QLampWidget::QLampWidget(QWidget *parent)
{
    this->setParent(parent);
}

QLampWidget::QLampWidget()
{
    this->setFixedWidth(32);
    this->setFixedHeight(32);
    this->setStatus(QLampWidget::on);
    this->color = "#f00";
}

QLampWidget::QLampWidget(QString color)
{
    this->setFixedWidth(32);
    this->setFixedHeight(32);
    this->color = color;
    this->setStatus(QLampWidget::on);
}


QLampWidget::QLampWidget(QString color, int status)
{
    this->setFixedWidth(32);
    this->setFixedHeight(32);
    this->color = color;
    this->setStatus(status);
}

int QLampWidget::getStatus() const
{
    return status;
}

void QLampWidget::setStatus(int value)
{
    status = value;
    this->update();
}

QSize QLampWidget::sizeHint() const {
    return QSize(32, 32);
}
