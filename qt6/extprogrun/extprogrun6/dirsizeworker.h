#ifndef DIRSIZEWORKER_H
#define DIRSIZEWORKER_H

#include "readlineworker.h"

class DirSizeWorker : public ReadLineWorker
{
public:
    explicit DirSizeWorker(QObject *parent = nullptr);

public slots:
    void onStringReady(const QString &data);

private:
    RegexParser *parser;
};

#endif // DIRSIZEWORKER_H
