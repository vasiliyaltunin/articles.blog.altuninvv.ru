#ifndef FLOATWINDOW_H
#define FLOATWINDOW_H

#include <QMenu>
#include <QMouseEvent>
#include <QWidget>
#include "textseparator.h"

namespace Ui {
class FloatWindow;
}

class FloatWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FloatWindow(QWidget *parent = nullptr);
    ~FloatWindow();

    void saveWidgetPosition();
    void readWidgetPosition();

private:
    Ui::FloatWindow *ui;
    QPoint oldPos;
    QTimer *clockTimer;
    QAction *quitAct;
    QMenu *conextMenu;
    #ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
    #endif // QT_NO_CONTEXTMENU
    TextSeparator* subMenuHeader;


protected:
     void mousePressEvent(QMouseEvent *evt);
     void mouseMoveEvent(QMouseEvent *evt);
     void mouseReleaseEvent(QMouseEvent *evt);


private slots:
     void updateTimer();
     void onQuitAction();
};

#endif // FLOATWINDOW_H
