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

#include "comboboxitemdelegate.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    values = new QList<CountryFlag>;

//    values->append(CountryFlag(-1, "Select flag", ""));
    values->append(CountryFlag(1," Russia", "russia.png"));
    values->append(CountryFlag(11, "Belarus", "belarus.png"));
    values->append(CountryFlag(22, "Slovakia", "slovakia.png"));
    values->append(CountryFlag(33, "Slovenia", "slovenia.png"));
    values->append(CountryFlag(44, "China", "china.png"));
    values->append(CountryFlag(55, "Mongolia","mongolia.png"));


    model = new QListViewModel();
    model->populate(values);
    this->ui->listView->setModel(model);

    model->insertAt(4,CountryFlag(66, "Japan", "japan.png"));

    //this->ui->listView->setItemDelegate(new ComboboxItemDelegate);

    newidx=0;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    newidx++;
    QString strIdx = QString().number(newidx);

    model->append(CountryFlag(newidx, "new country " + strIdx, "russia.png"));
}

void MainWindow::on_pushButton_2_clicked()
{
    model->update(ui->listView->currentIndex().row(), CountryFlag(66, "Japan", "japan.png"));
}

void MainWindow::on_pushButton_3_clicked()
{
    model->deleteRow(0);
}

void MainWindow::on_pushButton_4_clicked()
{
    model->insertAt(0, CountryFlag(66, "Japan", "japan.png"));
}
