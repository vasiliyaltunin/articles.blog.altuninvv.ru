/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
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
#include <QDebug>
#include <QMouseEvent>
#include <QDebug>
#include <QFont>
#include <QRect>

void QLampWidget::paintEvent(QPaintEvent *event)
{
    installEventFilter(this);
    QString onColor = this->color;
    QColor mainColorOn = QColor(onColor);
    QColor subColorOn = QColor(onColor);
    subColorOn.setHsl(0,100,95,0);


    QString aoffColor = this->offColor;
    QColor mainColorOff = QColor(aoffColor);
    QColor subColorOff = QColor(aoffColor);
    subColorOff.setHsl(0,100,95,0);

    QPainter painter(this);

    painter.setFont(this->captionFont);

    QFontMetrics metrics(painter.font());

    QRect bRect = metrics.boundingRect(QRect(0,0,this->getLampSize(),32),this->getCaptionAlign(),this->getCaption());;

    int heightOfText  = bRect.height();

    this->setFixedHeight(this->getLampSize()+heightOfText);

    int widthOfText = bRect.width();
    float xPos = 0;

    if (widthOfText > this->getLampSize())
    {
        this->setFixedWidth(bRect.width());
    }
    else
    {
        this->setFixedWidth(this->getLampSize());
    }

    QLinearGradient linearGrad(
                QPointF(xPos,
                    4),
                QPointF(xPos + this->getLampSize()-8,
                    this->getLampSize()-8));

    if (this->getStatus()==QLampWidget::on)
    {
        linearGrad.setColorAt(0, subColorOn);
        linearGrad.setColorAt(1, mainColorOn);
    } else  {
        linearGrad.setColorAt(0, subColorOff);
        linearGrad.setColorAt(1, mainColorOff);
    }


    QRect r;

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QPen(QColor("#f00"), 0.1));
    painter.setBrush(linearGrad);

    painter.drawEllipse(
                QRectF(xPos, 4,
                       this->getLampSize()-8, this->getLampSize()-8));

    painter.setBrush(QBrush(QColor(157,255,252,127)));
    QPen pen;
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);
    QRect border = QRect(0,this->getLampSize(),
                         this->getLampSize(), heightOfText);
    painter.drawRect(border);

    painter.setPen(QPen(QColor(this->captionColor), 1));
    painter.drawText(0,this->getLampSize(),
                     this->getLampSize(), heightOfText,
                     this->getCaptionAlign(),
                     this->getCaption(),
                     new QRect(0,this->getLampSize(),this->getLampSize(), heightOfText));
}

QLampWidget::QLampWidget(QWidget *parent)
{
    this->setParent(parent);
    this->setLampSize(32);
    this->setStatus(QLampWidget::on);
    this->color = "#f00";
    this->offColor = "#808080";
    this->captionColor = "#000";
    this->captionFont = this->font();
}

QLampWidget::QLampWidget()
{
    this->setLampSize(32);
    this->setStatus(QLampWidget::on);
    this->color = "#f00";
    this->offColor = "#808080";
    this->captionColor = "#000";
    this->captionFont = this->font();
}


QLampWidget::QLampWidget(QString color, QString offcolor, int status,  int size, QString id)
{
    this->setLampSize(size);

    this->color = color;
    this->offColor = offcolor;

    this->setStatus(status);

    this->setProperty("id",id);

    this->captionColor = "#000";
    this->captionFont = this->font();
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

void QLampWidget::mousePressEvent(QMouseEvent *event)
{
    switch (event->button()) {
        case Qt::LeftButton:
        {
            qDebug() << "Left Mouse button pressed";
            break;
        }
        case Qt::RightButton:
        {
            qDebug() << "Right Mouse button pressed";
            break;
        }
        case Qt::MiddleButton:
        {
            qDebug() << "Middle Mouse button pressed";
            break;
        }
        default:
        {
            qDebug() << "Other button pressed, id = "+QString::number(event->button());
            break;
        }
    }

    repaint();
    emit pressed();
}

void QLampWidget::mouseReleaseEvent(QMouseEvent *event)
{
    switch (event->button()) {
        case Qt::LeftButton:
        {
            qDebug() << "Left Mouse button released";
            emit clicked();
            break;
        }
        default:
        {
            qDebug() << "Other button released, id = "+QString::number(event->button());
            break;
        }
    }

    repaint();
    emit released();
}

void QLampWidget::setActiveColor(int count)
{
    this->status = QLampWidget::on;
    QColor mainColorOn = QColor(this->color);


    int lightness = mainColorOn.lightness() + count/5;

    if (lightness < 10) {
        lightness = 10;
    }

    if (lightness > 100) {
        lightness = 100;
    }

    mainColorOn.setHsl(mainColorOn.hslHue(), mainColorOn.hslSaturation(), lightness, mainColorOn.alpha());

    this->color = mainColorOn.name();
    repaint();
}

void QLampWidget::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees = event->angleDelta() / 8;

    if (numDegrees.y() > 0)
    {
        emit wheelUp(numDegrees.y());
    }
    else
    {
        emit wheelDown(numDegrees.y());
    }
}

void QLampWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug() << "Double clicked";
    emit doubleClicked();
}

void QLampWidget::toggle()
{
    if (this->status == QLampWidget::on)
    {
        this->status = QLampWidget::off;
    }
    else
    {
        this->status = QLampWidget::on;
    }
    this->update();
    emit this->toggled(this->getStatus());
}

int QLampWidget::getLampSize() const
{
    return lampSize;
}

void QLampWidget::setLampSize(int value)
{
    lampSize = value;
    this->setFixedWidth(value);
    this->setFixedHeight(value);
}

QString QLampWidget::getCaption() const
{
    return caption;
}

void QLampWidget::setCaption(const QString &value)
{
    caption = value;
    repaint();
}

QString QLampWidget::getCaptionColor() const
{
    return captionColor;
}

void QLampWidget::setCaptionColor(const QString &value)
{
    captionColor = value;
    repaint();
}

QFont QLampWidget::getCaptionFont() const
{
    return captionFont;
}

void QLampWidget::setCaptionFont(const QFont &value)
{
    captionFont = value;
    repaint();
}

int QLampWidget::getCaptionAlign() const
{
    return captionAlign;
}

void QLampWidget::setCaptionAlign(int value)
{
    captionAlign = value;
    repaint();
}
