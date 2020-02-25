#include "floatwindow.h"
#include "ui_floatwindow.h"

FloatWindow::FloatWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FloatWindow)
{
    ui->setupUi(this);

    setStyleSheet("#centralwidget { background-color: rgba(255, 255, 255, 100); border:1px solid #eee; }");
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

}

FloatWindow::~FloatWindow()
{
    delete ui;
}

void FloatWindow::mousePressEvent(QMouseEvent *evt)
{
    oldPos = evt->globalPos();
}

void FloatWindow::mouseMoveEvent(QMouseEvent *evt)
{
    const QPoint delta = evt->globalPos() - oldPos;
                move(x()+delta.x(), y()+delta.y());
                oldPos = evt->globalPos();
}
