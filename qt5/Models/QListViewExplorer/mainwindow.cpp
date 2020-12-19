/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how use QListView with model to display files from folder.
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->aDirList = new QFileInfoList();

    this->model = new QListViewExplorerModel();

    this->currentFolder = QDir(QDir::currentPath());

    this->model->getFolderList(this->currentFolder.absolutePath(),this->aDirList);


    this->ui->listView->setModel(model);

    this->ui->lineEdit->setText(QDir::currentPath());

    this->ui->listView->setWordWrap(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    if (this->aDirList->at(index.row()).isDir())
    {
        QString tmp = this->aDirList->at(index.row()).absoluteFilePath();
        model->getFolderList(this->aDirList->at(index.row()).absoluteFilePath(),this->aDirList);
        this->ui->lineEdit->setText(tmp);
    } else {
        QDesktopServices::openUrl(QUrl(this->aDirList->at(index.row()).absoluteFilePath()));
    }
}

void MainWindow::on_pushButton_clicked()
{
    currentFolder.cdUp();

    this->ui->lineEdit->setText(currentFolder.absolutePath());
    model->getFolderList(currentFolder.absolutePath(),this->aDirList);
}

void MainWindow::on_pushButton_3_clicked()
{
    this->ui->listView->setUniformItemSizes(false);
    this->ui->listView->setViewMode(QListView::ListMode);
}

void MainWindow::on_pushButton_2_clicked()
{
    this->ui->listView->setUniformItemSizes(true);
    this->ui->listView->setViewMode(QListView::IconMode);
}
