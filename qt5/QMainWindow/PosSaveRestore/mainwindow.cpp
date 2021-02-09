#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPoint pos;
    QSize size;

    state.RestoreState(pos, size);

    this->move(pos);
    this->resize(size);

}

MainWindow::~MainWindow()
{
    state.SaveState(this->pos(), this->size());
    delete ui;
}

