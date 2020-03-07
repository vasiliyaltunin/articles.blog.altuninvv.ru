#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <floatwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FloatWindow *fwin;
};
#endif // MAINWINDOW_H
