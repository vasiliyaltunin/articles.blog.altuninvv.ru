#ifndef QLAPM5BLOCKWIDGET_H
#define QLAPM5BLOCKWIDGET_H

#include <QLampWidget.h>
#include <QWidget>



class QLapm5BlockWidget: public QWidget
{
    Q_OBJECT

public:
    QLapm5BlockWidget();

    QList<QLampWidget *> getLamps() const;

private:
    QList<QLampWidget *> lamps;
};

#endif // QLAPM5BLOCKWIDGET_H
