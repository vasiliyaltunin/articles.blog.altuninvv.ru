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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtableviewmodel.h"
#include "wsuslogrecord.h"

#include <QMainWindow>

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
    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QList<WSUSLogRecord> *values;
    QTableViewModel *model;
};
#endif // MAINWINDOW_H
