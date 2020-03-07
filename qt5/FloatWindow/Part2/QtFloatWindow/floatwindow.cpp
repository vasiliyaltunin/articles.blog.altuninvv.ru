#include "floatwindow.h"
#include "ui_floatwindow.h"
#include <QTime>
#include <QTimer>

FloatWindow::FloatWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FloatWindow)
{
    ui->setupUi(this);

    setStyleSheet("#centralwidget { background-color: rgba(255, 255, 255, 100); border:1px solid #eee; }");
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

    ui->clockLabel->setText(QTime::currentTime().toString());

    clockTimer = new QTimer();

    clockTimer->setInterval(1000);

    clockTimer->start();

    connect(clockTimer, SIGNAL(timeout()), this, SLOT(updateTimer()));

    quitAct = new QAction(tr("Quit"), this);

    conextMenu = new QMenu(this);

    connect(quitAct, &QAction::triggered, this, &FloatWindow::onQuitAction);


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

void FloatWindow::updateTimer()
{
ui->clockLabel->setText(QTime::currentTime().toString());
}

void FloatWindow::onQuitAction()
{
exit(0);
}

void FloatWindow::contextMenuEvent(QContextMenuEvent *event)
{
conextMenu->addAction(quitAct);
conextMenu->exec(event->globalPos());
}
