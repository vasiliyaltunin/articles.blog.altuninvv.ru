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
