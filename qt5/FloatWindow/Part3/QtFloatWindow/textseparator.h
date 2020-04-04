#ifndef TEXTSEPARATOR_H
#define TEXTSEPARATOR_H

#include <QObject>
#include <QWidget>
#include <QWidgetAction>

class TextSeparator : public QWidgetAction
{
    Q_OBJECT
public:
    TextSeparator(QObject *parent, QString text, QString bgColor, QString textColor);
};

#endif // TEXTSEPARATOR_H
