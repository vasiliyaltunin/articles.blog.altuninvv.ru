#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QRandomGenerator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::drawMainAxis()
{
    QColor coordLineColor(255, 0, 0, 255);

    QPen apen = QPen(coordLineColor);
    apen.setWidth(5);
    painter->setPen(apen);

    painter->drawLine(QLine(0,0,300,0));
    painter->drawLine(QLine(0,0,0,300));

    painter->drawText(QPoint(5,13), "0,0");

    painter->drawText(QPoint(280,13), "300");
    painter->drawText(QPoint(5,295), "300");
}


void MainWindow::drawChildPicRel()
{
    painter->translate(QPoint(50,70));
    painter->save();

    QColor linesColor(0, 0, 255, 255);
    QPen apen = QPen(linesColor);
    apen.setWidth(3);
    painter->setPen(apen);

    painter->translate(QPoint(150,220));

    //Квадрат - дом
    painter->drawRect(-50,-50,100,100);

    //Квадрат - окно
    painter->drawRect(-30,-30,60,60);


    //Полигон - крыша и дымоход
    static const QPointF points[7] = {
        QPointF(-50.0, -50.0),
        QPointF(0.0, -100.0),
        QPointF(20.0, -80.0),
        QPointF(20.0, -110.0),
        QPointF(30.0, -110.0),
        QPointF(30.0, -70.0),
        QPointF(50.0, -50.0)
    };
    painter->drawConvexPolygon(points, 7);


    //Линия - крышка дымохода
    painter->drawLine(QLine(15,-110,35,-110));
    painter->drawLine(QLine(15,-110,25,-120));
    painter->drawLine(QLine(25,-120,35,-110));



    painter->restore();
    painter->translate(QPoint(50,50));

    int rainbowWidth = 200;
    int rainbowHeight = 200;
    int rainbowInRad = 30 * 16;
    int rainbowOutRad = 120 * 16;
    int rainbowArcHeight = 4;

    //Дуга - Радуга
    apen = QPen(QColor("red"));
    apen.setWidth(rainbowArcHeight);
    painter->setPen(apen);
    painter->drawArc(0,0,rainbowWidth,rainbowHeight,rainbowInRad,rainbowOutRad);

    apen.setWidth(rainbowArcHeight);

    apen = QPen(QColor("orange"));
    apen.setWidth(rainbowArcHeight);
    painter->setPen(apen);
    painter->drawArc(0,rainbowArcHeight,rainbowWidth,rainbowHeight,rainbowInRad,rainbowOutRad);

    apen = QPen(QColor("yellow"));
    apen.setWidth(rainbowArcHeight);
    painter->setPen(apen);
    painter->drawArc(0,rainbowArcHeight*2,rainbowWidth,rainbowHeight,rainbowInRad,rainbowOutRad);

    apen = QPen(QColor("green"));
    apen.setWidth(rainbowArcHeight);
    painter->setPen(apen);
    painter->drawArc(0,rainbowArcHeight*3,rainbowWidth,rainbowHeight,rainbowInRad,rainbowOutRad);

    apen = QPen(QColor("lightblue"));
    apen.setWidth(rainbowArcHeight);
    painter->setPen(apen);
    painter->drawArc(0,rainbowArcHeight*4,rainbowWidth,rainbowHeight,rainbowInRad,rainbowOutRad);

    apen = QPen(QColor("blue"));
    apen.setWidth(rainbowArcHeight);
    painter->setPen(apen);
    painter->drawArc(0,rainbowArcHeight*5,rainbowWidth,rainbowHeight,rainbowInRad,rainbowOutRad);

    apen = QPen(QColor("violet"));
    apen.setWidth(rainbowArcHeight);
    painter->setPen(apen);
    painter->drawArc(0,rainbowArcHeight*6,rainbowWidth,rainbowHeight,rainbowInRad,rainbowOutRad);

    painter->restore();
    painter->translate(QPoint(220,-90));

    drawSun();

}

void MainWindow::drawClouds()
{
    painter->translate(QPoint(0,20));

    painter->save();
    painter->translate(QPoint(20,20));
    painter->scale(0.8,0.8);
    drawCloud(121);
    painter->restore();

    painter->save();
    painter->translate(QPoint(100,60));
    painter->scale(1.2,1.2);
    drawCloud(122);
    painter->restore();

    painter->save();
    painter->translate(QPoint(240,100));
    painter->scale(0.6,0.6);
    drawCloud(123);
    painter->restore();

    painter->save();
    painter->translate(QPoint(225,2));
    painter->scale(0.9,0.9);
    drawCloud(124);
    painter->restore();
}

void MainWindow::drawCloud(int seed)
{
    QRandomGenerator prng(seed);

    QColor linesColor(0, 0, 255, 255);
    QPen apen = QPen(linesColor);

//    painter->translate(QPoint(150,150));
    painter->setBrush(Qt::white);

    //
    apen = QPen(QColor("white"));
    apen.setWidth(3);
    painter->setPen(apen);

    painter->drawEllipse(0, 0, 30+prng.bounded(10),30+prng.bounded(10));

    painter->translate(QPoint(20,-10));
    painter->drawEllipse(0, 0, 30+prng.bounded(10),30+prng.bounded(10));

    painter->translate(QPoint(20,0));
    painter->drawEllipse(0, 0, 30+prng.bounded(10),30+prng.bounded(10));

    painter->translate(QPoint(20,10));
    painter->drawEllipse(0, 0, 30+prng.bounded(10),30+prng.bounded(10));

    painter->translate(QPoint(-20,10));
    painter->drawEllipse(0, 0, 30+prng.bounded(10),30+prng.bounded(10));

    painter->translate(QPoint(-20,0));
    painter->drawEllipse(0, 0, 30+prng.bounded(10),30+prng.bounded(10));

}

void MainWindow::drawSun()
{
    int beamLength = 40;
    QColor linesColor(0, 0, 255, 255);
    QPen apen = QPen(linesColor);
    apen.setWidth(3);
    painter->setPen(apen);

    //Элипс - круг - солнце
    apen = QPen(QColor("yellow"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(0, 0, 50,50);

    //рисуем лучи
    painter->translate(QPoint(25,25));

    apen.setWidth(4);
    painter->setPen(apen);
    painter->drawLine(QLine(0,0,0,beamLength*-1));

    for (int i = 0; i < 7; i++) {
        painter->rotate(45);
        painter->drawLine(QLine(0,0,0,beamLength*-1));
    }
}

void MainWindow::drawCoordAxis(int length)
{
    QColor coordLineColor(255, 0, 0, 255);

    QPen apen = QPen(coordLineColor);
    apen.setWidth(5);
    painter->setPen(apen);

    painter->drawLine(QLine(0,0,length,0));
    painter->drawLine(QLine(0,0,0,length));
}



void MainWindow::paintEvent(QPaintEvent *)
{
    painter= new QPainter(this);

    drawMainAxis();

    drawClouds();

    drawChildPicRel();

    painter->end();
}
