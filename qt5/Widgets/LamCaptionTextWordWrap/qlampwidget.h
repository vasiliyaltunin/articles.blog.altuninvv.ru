/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
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
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void wheelEvent(QWheelEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

public:
    explicit QLampWidget(QWidget *parent);

    QLampWidget();
    QLampWidget(QString color, QString offcolor, int status, int size, QString id);

    int getStatus() const;
    void setStatus(int value);

    static const int on = 1;
    static const int off = 0;

    QString getOffColor() const;
    void setOffColor(const QString &value);

    void setSize(int width, int height);
    void setActiveColor(int count);

    void toggle();
    int getLampSize() const;
    void setLampSize(int value);

    QString getCaption() const;
    void setCaption(const QString &value);

    QString getCaptionColor() const;
    void setCaptionColor(const QString &value);

    QFont getCaptionFont() const;
    void setCaptionFont(const QFont &value);

    int getCaptionAlign() const;
    void setCaptionAlign(int value);

private:
    int captionAlign;
    QFont captionFont;
    QString captionColor;
    QString caption;
    int lampSize;
    int status;
    QString color;
    QString offColor;


signals:
    void clicked();
    void released();
    void pressed();
    void doubleClicked();
    void toggled(int status);
    void wheelUp(int count);
    void wheelDown(int count);

};

#endif // QLAMPWIDGET_H
