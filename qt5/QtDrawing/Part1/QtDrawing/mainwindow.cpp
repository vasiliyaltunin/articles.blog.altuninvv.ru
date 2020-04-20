#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>

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

void MainWindow::drawChildPicAbs()
{

    QColor linesColor(0, 0, 255, 255);
    QPen apen = QPen(linesColor);
    apen.setWidth(3);
    painter->setPen(apen);

    //Квадрат - дом
    painter->drawRect(100,100,100,100);

    //Квадрат - окно
    painter->drawRect(120,120,60,60);

    //Полигон - крыша и дымоход
    static const QPointF points[7] = {
        QPointF(100.0, 100.0),
        QPointF(150.0, 50.0),
        QPointF(170.0, 70.0),
        QPointF(170.0, 50.0),
        QPointF(180.0, 50.0),
        QPointF(180.0, 80.0),
        QPointF(200.0, 100.0)
    };
    painter->drawConvexPolygon(points, 7);


    //Линия - крышка дымохода
    painter->drawLine(QLine(165,50,185,50));
    painter->drawLine(QLine(165,50,175,40));
    painter->drawLine(QLine(175,40,185,50));


    //Дуга - Радуга
    apen = QPen(QColor("red"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,10,100,100,30*16,120*16);

    apen = QPen(QColor("orange"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,12,100,100,30*16,120*16);

    apen = QPen(QColor("yellow"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,14,100,100,30*16,120*16);

    apen = QPen(QColor("green"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,16,100,100,30*16,120*16);

    apen = QPen(QColor("lightblue"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,18,100,100,30*16,120*16);

    apen = QPen(QColor("blue"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,20,100,100,30*16,120*16);

    apen = QPen(QColor("violet"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawArc(100,22,100,100,30*16,120*16);


    //Элипс - круг - солнце
    apen = QPen(QColor("yellow"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->drawEllipse(220, 30, 50,50);

}

void MainWindow::drawChildPicRel()
{

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



    painter->resetTransform();
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

    painter->resetTransform();
    painter->translate(QPoint(240,30));


    //Элипс - круг - солнце
    apen = QPen(QColor("yellow"));
    apen.setWidth(2);
    painter->setPen(apen);
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(0, 0, 50,50);

}

void MainWindow::paintEvent(QPaintEvent *)
{
    painter= new QPainter(this);

    drawMainAxis();

    //drawChildPic();

    drawChildPicRel();

    painter->end();
}
