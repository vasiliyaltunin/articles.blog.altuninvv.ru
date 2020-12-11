/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how to extend model with class to use with model with QComboBox widget in Qt5
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    values = new QList<CountryFlag>;

    values->append(CountryFlag(-1, "Select flag", "Capital"));
    values->append(CountryFlag(1," Russia", "Moscow"));
    values->append(CountryFlag(11, "Belarus", "Minsk"));
    values->append(CountryFlag(22, "Slovakia", "Bratislava"));
    values->append(CountryFlag(33, "Slovenia", "Ljubljana"));
    values->append(CountryFlag(44, "China", "Beijing"));
    values->append(CountryFlag(55, "Mongolia","Ulaanbaatar"));


    model = new QComboBoxModel();
    model->populate(values);
    this->ui->comboBox->setModel(model);

    model->insertAt(4,CountryFlag(66, "Japan", "Tokyo"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    newidx++;
    QString strIdx = QString().number(newidx);

    model->append(CountryFlag(newidx, "new country " + strIdx, "a Capital"));
}

void MainWindow::on_pushButton_2_clicked()
{
    model->update(ui->comboBox->currentIndex(), CountryFlag(66, "Japan", "Tokyo"));


}

void MainWindow::on_pushButton_3_clicked()
{
    model->deleteRow(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    model->insertAt(0, CountryFlag(66, "Japan", "Tokyo"));
}
