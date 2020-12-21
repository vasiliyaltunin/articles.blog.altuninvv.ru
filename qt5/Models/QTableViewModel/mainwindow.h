#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "countryflag.h"
#include "qtableviewmodel.h"

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
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QList<CountryFlag> *values;
    QTableViewModel *model;
    int newidx;

};
#endif // MAINWINDOW_H
