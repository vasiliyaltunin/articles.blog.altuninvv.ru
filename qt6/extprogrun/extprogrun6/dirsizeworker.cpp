#include "dirsizeworker.h"
#include <QDebug>

DirSizeWorker::DirSizeWorker(QObject *parent)
    : ReadLineWorker{parent}
{
    this->parser = new RegexParser("\\s*(?<files>\\d*)\\s*файлов\\s*(?<foldersize>[\\d\\xa0]*)\\sбайт");

    QObject::connect(this, ReadLineWorker::stringRead,
                     this, DirSizeWorker::onStringReady);
}

void DirSizeWorker::onStringReady(const QString &data)
{
    qDebug() << "NEW Worker:" << data;


    QString files = this->parser->parseGroup(data,"files");
    QString foldersize = this->parser->parseGroup(data,"foldersize");

    if (!files.isEmpty() && !foldersize.isEmpty())
    {
        qDebug() << files;
        qDebug() << foldersize;

        RegexParser p = RegexParser("\\xa0");
        QString folderFreeSizeNumber = p.replace(foldersize,"");

        qDebug() << "Число: " << folderFreeSizeNumber;

        bool isOk = false;
        double folderFreeSizeMb = folderFreeSizeNumber.toDouble(&isOk);
        qDebug() << "isOk" << isOk;
        qDebug() << folderFreeSizeMb;

        int diskMbSize = folderFreeSizeMb / 1024 / 1024;
        qDebug() << diskMbSize << "Mb";
    }
}
