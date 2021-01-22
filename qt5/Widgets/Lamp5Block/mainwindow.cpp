/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how to create widget container - block of lamps
**
****************************************************************************/

#include "mainwindow.h"
#include "qlapm5blockwidget.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QVBoxLayout *vlay = new QVBoxLayout();

    QHBoxLayout *hlay1 = new QHBoxLayout();


    QLapm5BlockWidget *block1 =  new QLapm5BlockWidget();

    hlay1->addWidget(block1);

    hlay1->addStretch(1);
    vlay->addItem(hlay1);

    vlay->addStretch(1);

    ui->centralwidget->setLayout(vlay);

    block1->getLamps().at(2)->setStatus(QLampWidget::off);


}

MainWindow::~MainWindow()
{
    delete ui;
}

