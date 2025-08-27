#ifndef DIRSIZEWORKER_H
#define DIRSIZEWORKER_H

#include "worker.h"

class DirSizeWorker : public Worker
{
public:
    explicit DirSizeWorker(QObject *parent = nullptr);
    virtual void onRead(const QString &data);
};

#endif // DIRSIZEWORKER_H
