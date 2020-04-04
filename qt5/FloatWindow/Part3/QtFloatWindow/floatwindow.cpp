#include "floatwindow.h"
#include "ui_floatwindow.h"
#include <QSettings>
#include <QTime>
#include <QTimer>
#include "textseparator.h"

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

    quitAct = new QAction(tr("&Quit"), this);

    conextMenu = new QMenu(this);

    connect(quitAct, &QAction::triggered, this, &FloatWindow::onQuitAction);

    subMenuHeader = new TextSeparator(NULL,"Clocks","#999","#fff");

    conextMenu->addAction(subMenuHeader);
    conextMenu->addAction(quitAct);

    readWidgetPosition();
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
    conextMenu->exec(event->globalPos());
}


void FloatWindow::saveWidgetPosition()
{
    QSettings settings("AltuninVV", "Clocks");

    settings.beginGroup("FloatWindow");
        settings.setValue("pos", pos());
    settings.endGroup();
}

void FloatWindow::readWidgetPosition()
{

    QSettings settings("AltuninVV", "Clocks");

    settings.beginGroup("FloatWindow");
        QPoint oldPoint = settings.value("pos", QPoint(0, 0)).toPoint();

        if (oldPoint.x()!=0 && oldPoint.y()!=0) //if no prev values just do nothing
        {
            move(settings.value("pos", QPoint(0, 0)).toPoint());
        }
    settings.endGroup();
}

void FloatWindow::mouseReleaseEvent(QMouseEvent *evt)
{
    saveWidgetPosition();
}

