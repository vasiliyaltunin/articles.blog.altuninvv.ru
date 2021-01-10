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

    QHBoxLayout *hlay1 = new QHBoxLayout();

    QLampWidget *lamp1 = new QLampWidget("#557d00","#F00",QLampWidget::on, 32, "2");
    lamp1->setCaption("Left Right Top Bottom");
    lamp1->setCaptionAlign(Qt::TextWordWrap);
    hlay1->addWidget(lamp1);


    QLampWidget *lamp2 = new QLampWidget("#557d00","#F00",QLampWidget::on, 64, "2");
    lamp2->setCaption("Left Right Top Bottom");
    lamp2->setCaptionAlign(Qt::TextWordWrap);
    hlay1->addWidget(lamp2);

    hlay1->addStretch(1);
    vlay->addItem(hlay1);

    QHBoxLayout *hlay3 = new QHBoxLayout();

    QLampWidget *lamp3 = new QLampWidget("#557d00","#F00",QLampWidget::on, 96, "2");
    lamp3->setCaption("Left Right Top Bottom");
    lamp3->setCaptionAlign(Qt::TextWordWrap);
    hlay3->addWidget(lamp3);

    hlay3->addStretch(1);
    vlay->addItem(hlay3);

    QHBoxLayout *hlay4 = new QHBoxLayout();

    QLampWidget *lamp4 = new QLampWidget("#557d00","#F00",QLampWidget::on, 128, "2");
    lamp4->setCaption("Left Right Top Bottom");
    lamp4->setCaptionAlign(Qt::TextWordWrap);
    hlay4->addWidget(lamp4);


    hlay4->addStretch(1);
    vlay->addItem(hlay4);

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
