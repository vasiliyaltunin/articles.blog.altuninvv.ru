/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Block of lamps widget
**
****************************************************************************/

#include "qlapm5blockwidget.h"

#include <QVBoxLayout>

QLapm5BlockWidget::QLapm5BlockWidget()
{

    QLampWidget *lamp1 = new QLampWidget("#557d00","#F00",QLampWidget::on, 32, "2");
    lamp1->setCaption("L1");
    lamp1->setCaptionAlign(Qt::AlignCenter);
    QLampWidget *lamp2 = new QLampWidget("#557d00","#F00",QLampWidget::on, 32, "2");
    lamp2->setCaption("L2");
    lamp2->setCaptionAlign(Qt::AlignCenter);
    QLampWidget *lamp3 = new QLampWidget("#557d00","#F00",QLampWidget::on, 32, "2");
    lamp3->setCaption("L3");
    lamp3->setCaptionAlign(Qt::AlignCenter);
    QLampWidget *lamp4 = new QLampWidget("#557d00","#F00",QLampWidget::on, 32, "2");
    lamp4->setCaption("L4");
    lamp4->setCaptionAlign(Qt::AlignCenter);
    QLampWidget *lamp5 = new QLampWidget("#557d00","#F00",QLampWidget::on, 32, "2");
    lamp5->setCaption("L5");
    lamp5->setCaptionAlign(Qt::AlignCenter);

    QHBoxLayout *hlay1 = new QHBoxLayout();

    hlay1->addWidget(lamp1);
    hlay1->addWidget(lamp2);
    hlay1->addWidget(lamp3);
    hlay1->addWidget(lamp4);
    hlay1->addWidget(lamp5);

    hlay1->addStretch(1);

    this->setLayout(hlay1);

    lamps.append(lamp1);
    lamps.append(lamp2);
    lamps.append(lamp3);
    lamps.append(lamp4);
    lamps.append(lamp5);
}

QList<QLampWidget *> QLapm5BlockWidget::getLamps() const
{
    return lamps;
}
