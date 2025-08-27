/****************************************************************************
**
** Copyright 2025 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Qt6 Regexp parser class
**
****************************************************************************/

#include "regexparser.h"
#include <QRegularExpression>

RegexParser::RegexParser(const QString &pattern)
{
    this->setPattern(pattern);
}

QString RegexParser::parseGroup(QString data, QString group)
{
    QRegularExpressionMatchIterator i = this->regularExp->globalMatch(data);

    if(!this->regularExp->isValid())
    {
        qDebug() << "ERROR: "<< this->regularExp->errorString();
        exit(EXIT_FAILURE);
    }

    while (i.hasNext()) {
        QRegularExpressionMatch next = i.next();
        qDebug() << ">>" << next.captured(group);
        return next.captured(group);
    }

    return QString();
}

void RegexParser::setPattern(QString pattern)
{
    this->pattern = pattern;
    this->regularExp = new QRegularExpression(pattern);
}

QString RegexParser::replace(QString data, const QString &replace)
{
    QRegularExpression re(this->pattern);

    data.replace(re,replace);

    return data;
}

void RegexParser::parseAll(QString data)
{
    QRegularExpressionMatchIterator i = this->regularExp->globalMatch(data);

    if(!this->regularExp->isValid())
    {
        qDebug() << "ERROR: "<< this->regularExp->errorString();
        exit(EXIT_FAILURE);
    }

    while (i.hasNext()) {
        QRegularExpressionMatch next = i.next();
        for (int var = 1; var < next.capturedTexts().count(); ++var) {
            QString cap = next.captured(var);
            if (!cap.trimmed().isEmpty())
            {
                emit matched(cap.trimmed());
            }

        }
    }
}
