#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "floatwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fwin = new FloatWindow();
    fwin->show();
}

MainWindow::~MainWindow()
{
    fwin->close();
    delete ui;

}

