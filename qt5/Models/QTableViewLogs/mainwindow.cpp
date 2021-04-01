/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how to show logs loaded from file into QTableView widget in Qt5
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wsuslogparser.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->values = new QList<WSUSLogRecord>();

    WSUSLogParser *lp = new WSUSLogParser(this->values);

    lp->Load("log.txt");

    model = new QTableViewModel();

    model->populate(values);

    this->ui->tableView->setModel(model);

    this->ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{

    int curr = ui->tableView->currentIndex().row();

    qDebug() << curr;

    ui->textBrowser->setText(values->at(curr).getData());
}
