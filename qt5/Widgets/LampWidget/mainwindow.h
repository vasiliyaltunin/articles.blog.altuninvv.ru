﻿/****************************************************************************
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlampwidget.h"

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn1_toggled(bool checked);
    void on_all_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QLampWidget *lamp;
    QLampWidget *lamp2;

    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
};
#endif // MAINWINDOW_H
