/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Simple widget - lamp.
**
****************************************************************************/

#ifndef QLAMPWIDGET_H
#define QLAMPWIDGET_H

#include <QSize>
#include <QWidget>

class QLampWidget  : public QWidget
{    

    Q_OBJECT

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual QSize sizeHint() const;
public:
    explicit QLampWidget(QWidget *parent);

    QLampWidget();
    QLampWidget(QString color);
    QLampWidget(QString color, int status);
    int getStatus() const;
    void setStatus(int value);

    static const int on = 1;
    static const int off = 0;

private:
    int status;
    QString color;
};

#endif // QLAMPWIDGET_H
