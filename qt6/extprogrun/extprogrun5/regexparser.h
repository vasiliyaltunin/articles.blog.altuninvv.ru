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

private:
    QString pattern;
    QRegularExpression *regularExp;
};

#endif // REGEXPARSER_H
