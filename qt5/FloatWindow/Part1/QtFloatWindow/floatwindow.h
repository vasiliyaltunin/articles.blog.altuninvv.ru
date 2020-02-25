#ifndef FLOATWINDOW_H
#define FLOATWINDOW_H

#include <QMouseEvent>
#include <QWidget>

namespace Ui {
class FloatWindow;
}

class FloatWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FloatWindow(QWidget *parent = nullptr);
    ~FloatWindow();

private:
    Ui::FloatWindow *ui;
    QPoint oldPos;

protected:
     void mousePressEvent(QMouseEvent *evt);
     void mouseMoveEvent(QMouseEvent *evt);

};

#endif // FLOATWINDOW_H
