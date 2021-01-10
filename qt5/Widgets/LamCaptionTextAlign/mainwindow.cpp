/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how to create simple widget - lamp.
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *vlay = new QVBoxLayout();

    QHBoxLayout *hlay2 = new QHBoxLayout();

    QLampWidget *lamp3 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp3->setCaption("Left");
    lamp3->setCaptionAlign(Qt::AlignLeft);
    hlay2->addWidget(lamp3);

    QLampWidget *lamp4 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp4->setCaption("Center");
    lamp4->setCaptionAlign(Qt::AlignHCenter);
    hlay2->addWidget(lamp4);

    QLampWidget *lamp5 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp5->setCaption("Right");
    lamp5->setCaptionAlign(Qt::AlignRight);
    hlay2->addWidget(lamp5);

    hlay2->addStretch(1);

    vlay->addLayout(hlay2);

    QHBoxLayout *hlay3 = new QHBoxLayout();


    QLampWidget *lamp7 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp7->setCaption("Top Left");
    lamp3->setCaptionAlign(Qt::AlignLeft | Qt::AlignTop);
    hlay3->addWidget(lamp7);

    QLampWidget *lamp6 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp6->setCaption("Top Center");
    lamp6->setCaptionAlign(Qt::AlignHCenter  | Qt::AlignTop);
    hlay3->addWidget(lamp6);


    QLampWidget *lamp8 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp8->setCaption("Top Right");
    lamp8->setCaptionAlign(Qt::AlignRight |  Qt::AlignTop );
    hlay3->addWidget(lamp8);

    hlay3->addStretch(1);

    vlay->addLayout(hlay3);

    QHBoxLayout *hlay4 = new QHBoxLayout();

    QLampWidget *lamp10 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp10->setCaption("Mid Left");
    lamp10->setCaptionAlign(Qt::AlignVCenter |Qt::AlignLeft);
    hlay4->addWidget(lamp10);

    QLampWidget *lamp11 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp11->setCaption("Mid Center");
    lamp11->setCaptionAlign(Qt::AlignVCenter |Qt::AlignHCenter);
    hlay4->addWidget(lamp11);

    QLampWidget *lamp12 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp12->setCaption("Mid Right");
    lamp12->setCaptionAlign(Qt::AlignVCenter |Qt::AlignRight);
    hlay4->addWidget(lamp12);

    hlay4->addStretch(1);

    vlay->addLayout(hlay4);


    QHBoxLayout *hlay5 = new QHBoxLayout();

    QLampWidget *lamp13 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp13->setCaption("Bot Left");
    lamp13->setCaptionAlign(Qt::AlignBottom |Qt::AlignLeft);
    hlay5->addWidget(lamp13);

    QLampWidget *lamp14 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp14->setCaption("Bot Center");
    lamp14->setCaptionAlign(Qt::AlignBottom |Qt::AlignHCenter);
    hlay5->addWidget(lamp14);

    QLampWidget *lamp15 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp15->setCaption("Bot Right");
    lamp15->setCaptionAlign(Qt::AlignBottom |Qt::AlignRight);
    hlay5->addWidget(lamp15);

    hlay5->addStretch(1);

    vlay->addLayout(hlay5);


    vlay->addStretch(1);

    ui->centralwidget->setLayout(vlay);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lampToggled(int status)
{
    QLampWidget *lamp = qobject_cast<QLampWidget*>(sender());
    if ( lamp != NULL )
    {
        qDebug() << "Lamp toggled: " + QString::number(status) + " id: " + lamp->property("id").toString();
    }
    else
    {
        qFatal("Lamp pointer is NULL!");
    }
}

void MainWindow::clicked()
{
    QLampWidget *lamp = qobject_cast<QLampWidget*>(sender());
    if( lamp != NULL )
    {
        lamp->toggle();
    }
    else
    {
        qFatal("Lamp pointer is NULL!");
    }
}

void MainWindow::wheelUp(int count)
{
    QLampWidget *lamp = qobject_cast<QLampWidget*>(sender());
    if( lamp != NULL )
    {
        lamp->setActiveColor(count);
    }
    else
    {
        qFatal("Lamp pointer is NULL!");
    }

    qDebug() << "Wheel up - count = " +QString::number(count) + " id: " + lamp->property("id").toString();;

}

void MainWindow::wheelDown(int count)
{
    QLampWidget *lamp = qobject_cast<QLampWidget*>(sender());
    if( lamp != NULL )
    {
        lamp->setActiveColor(count);
    }
    else
    {
        qFatal("Lamp pointer is NULL!");
    }

    qDebug() << "Wheel down - count = " +QString::number(count) + " id: " + lamp->property("id").toString();;
}
