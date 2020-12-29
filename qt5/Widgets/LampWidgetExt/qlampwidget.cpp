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
#include "qlampwidget.h"
#include "qlampwidget.h"
#include "qlampwidget.h"
#include "qlampwidget.h"

#include <QPainter>
#include <QPen>

void QLampWidget::paintEvent(QPaintEvent *event)
{
    QString onColor = this->color;
    QColor mainColorOn = QColor(onColor);
    QColor subColorOn = QColor(onColor);
    subColorOn.setHsl(0,100,95,0);


    QString aoffColor = this->offColor;
    QColor mainColorOff = QColor(aoffColor);
    QColor subColorOff = QColor(aoffColor);
    subColorOff.setHsl(0,100,95,0);

    QLinearGradient linearGrad(QPointF(4, 4), QPointF(this->width()-4, this->height()-4));

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

    painter.drawEllipse(QRectF(4,4,this->width()-8,this->height()-8));


}

QLampWidget::QLampWidget(QWidget *parent)
{
    this->setParent(parent);
    this->setFixedWidth(32);
    this->setFixedHeight(32);
    this->setStatus(QLampWidget::on);
    this->color = "#f00";
    this->offColor = "#808080";
}

QLampWidget::QLampWidget()
{
    this->setFixedWidth(32);
    this->setFixedHeight(32);
    this->setStatus(QLampWidget::on);
    this->color = "#f00";
    this->offColor = "#808080";
}

QLampWidget::QLampWidget(QString color)
{
    this->setFixedWidth(32);
    this->setFixedHeight(32);
    this->color = color;
    this->setStatus(QLampWidget::on);
    this->offColor = "#808080";
}


QLampWidget::QLampWidget(QString color, int status)
{
    this->setFixedWidth(32);
    this->setFixedHeight(32);
    this->color = color;
    this->setStatus(status);
    this->offColor = "#808080";
}

QLampWidget::QLampWidget(QString color, QString offcolor, int status)
{
    this->setFixedWidth(32);
    this->setFixedHeight(32);
    this->color = color;
    this->offColor = offcolor;
    this->setStatus(status);
}

QLampWidget::QLampWidget(QString color, QString offcolor, int status, int wwidth, int wheight)
{
    this->color = color;
    this->offColor = offcolor;
    this->setStatus(status);
    this->setSize(wwidth, wheight);
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

QString QLampWidget::getOffColor() const
{
    return offColor;
}

void QLampWidget::setOffColor(const QString &value)
{
    offColor = value;
}

void QLampWidget::setSize(int width, int height)
{
    this->setFixedWidth(width);
    this->setFixedHeight(height);
}
