/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** BasicSerial - demonstrate how to connect to serial (COM) port and read
** data.
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    sm = new SerialPortManager("COM4");


    serialRdr = new QSerialIO(sm->getSerialPort());
}


MainWindow::~MainWindow()
{
    delete ui;
}

