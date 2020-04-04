#include "textseparator.h"

#include <QLabel>
#include <QWidgetAction>

TextSeparator::TextSeparator(QObject *parent, QString text, QString bgColor, QString textColor) : QWidgetAction(parent)
{
    QLabel* tLabel = new QLabel(text);
    tLabel->setMinimumHeight(26);

    tLabel->setStyleSheet("background: "+bgColor+"; color: "+textColor+"; font-weight: bold;");

    tLabel->setAlignment(Qt::AlignCenter);

    this->setDefaultWidget(tLabel);
}
