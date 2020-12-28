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
    QHBoxLayout *hlay2 = new QHBoxLayout();
    QHBoxLayout *hlay3 = new QHBoxLayout();


    lamp = new QLampWidget();
    hlay1->addWidget(lamp);
    btn1 = new QPushButton("Toggle");
    btn1->setCheckable(true);
    btn1->setChecked(true);
    btn1->setProperty("lamp",1);
    connect(btn1, SIGNAL(toggled(bool)), this, SLOT(on_btn1_toggled(bool)));
    hlay1->addWidget(btn1);
    vlay->addLayout(hlay1);


    lamp2 = new QLampWidget("#557d00");
    hlay2->addWidget(lamp2);
    btn2 = new QPushButton("Toggle");
    btn2->setCheckable(true);
    btn2->setChecked(true);
    btn2->setProperty("lamp",2);
    connect(btn2, SIGNAL(toggled(bool)), this, SLOT(on_btn1_toggled(bool)));
    hlay2->addWidget(btn2);
    vlay->addLayout(hlay2);


    btn3 = new QPushButton("Toggle all");
    btn3->setCheckable(true);
    btn3->setChecked(true);
    connect(btn3, SIGNAL(toggled(bool)), this, SLOT(on_all_toggled(bool)));
    hlay3->addWidget(btn3);

    vlay->addLayout(hlay3);

    hlay1->addStretch(1);
    hlay2->addStretch(1);
    hlay3->addStretch(1);

    vlay->addStretch(1);

    ui->centralwidget->setLayout(vlay);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn1_toggled(bool checked)
{
    QPushButton* abtn = qobject_cast<QPushButton*>(sender());
    if( abtn != NULL )
    {
        switch (abtn->property("lamp").toInt()) {
            case 1: {
                if (checked)
                {
                    lamp->setStatus(QLampWidget::on);
                } else {
                    lamp->setStatus(QLampWidget::off);
                }
            }
            break;

            case 2: {
                if (checked)
                {
                    lamp2->setStatus(QLampWidget::on);
                } else {
                    lamp2->setStatus(QLampWidget::off);
                }
            }
            break;
        }
    }
}

void MainWindow::on_all_toggled(bool checked)
{
    if (lamp->getStatus() == QLampWidget::off)
    {
        lamp->setStatus(QLampWidget::on);
        btn1->setChecked(true);
    } else {
        lamp->setStatus(QLampWidget::off);
        btn1->setChecked(false);
    }

    if (lamp2->getStatus() == QLampWidget::off)
    {
        lamp2->setStatus(QLampWidget::on);
        btn2->setChecked(true);
    } else {
        lamp2->setStatus(QLampWidget::off);
        btn2->setChecked(false);
    }

}
