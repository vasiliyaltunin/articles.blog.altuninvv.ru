/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how to process mouse input in simple widget - lamp.
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

    lamp = new QLampWidget("#557d00","#F00",QLampWidget::on, 32, 32);
    hlay1->addWidget(lamp);

    lamp2 = new QLampWidget("#557d00","#F00",QLampWidget::off, 32, 32);
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
