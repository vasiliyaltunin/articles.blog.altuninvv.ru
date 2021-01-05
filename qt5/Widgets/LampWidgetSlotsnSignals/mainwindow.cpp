/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
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

    lamp = new QLampWidget("#557d00","#F00",QLampWidget::on, 1);
    hlay1->addWidget(lamp);

    QObject::connect(lamp, SIGNAL(toggled(int)),this,SLOT(lampToggled(int)));
    QObject::connect(lamp, SIGNAL(clicked()),this,SLOT(clicked()));
    QObject::connect(lamp, SIGNAL(wheelUp(int)),this,SLOT(wheelUp(int)));
    QObject::connect(lamp, SIGNAL(wheelDown(int)),this,SLOT(wheelDown(int)));

    lamp->toggle();

    lamp2 = new QLampWidget("#557d00","#F00",QLampWidget::off, 2);
    lamp2->toggle();
    QObject::connect(lamp2, SIGNAL(toggled(int)),this,SLOT(lampToggled(int)));
    QObject::connect(lamp2, SIGNAL(clicked()),this,SLOT(clicked()));
    QObject::connect(lamp2, SIGNAL(wheelUp(int)),this,SLOT(wheelUp(int)));
    QObject::connect(lamp2, SIGNAL(wheelDown(int)),this,SLOT(wheelDown(int)));

    hlay1->addWidget(lamp2);


    vlay->addLayout(hlay1);

    hlay1->addStretch(1);

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
