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

    lamp1 = new QLampWidget("#557d00","#F00",QLampWidget::on, 32, "2");

    model = new QLampWidgetModel();
    lamp1->setModel(model);

    lampStatus = QString::number(QLampWidget::off);

    model->populate(&lampStatus);

    lamp1->setCaption("Lamp1");
    hlay1->addWidget(lamp1);

    hlay1->addStretch(1);
    vlay->addItem(hlay1);

    vlay->addStretch(1);

    ui->centralwidget->setLayout(vlay);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (lamp1->getStatus() == QLampWidget::on) {
        lampStatus = QString::number(QLampWidget::off);
    }
    else
    {
        lampStatus = QString::number(QLampWidget::on);
    }
    model->populate(&lampStatus);
}
