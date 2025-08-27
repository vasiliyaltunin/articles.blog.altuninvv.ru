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

#ifndef REGEXPARSER_H
#define REGEXPARSER_H

#include <QObject>
#include <QRegularExpression>
#include <QString>


class RegexParser : public QObject
{
    Q_OBJECT
signals:
    void matched(QString data);

public:
    explicit RegexParser(const QString &pattern);
    QString parseGroup(QString data, QString group);
    void setPattern(QString pattern);
    QString replace(QString data, const QString &replace);
    void parseAll(QString data);

private:
    QString pattern;
    QRegularExpression *regularExp;
};

#endif // REGEXPARSER_H
