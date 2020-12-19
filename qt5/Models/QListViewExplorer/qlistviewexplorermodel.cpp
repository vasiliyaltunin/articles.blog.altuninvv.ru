/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how use QListView with model to display files from folder.
**
****************************************************************************/

#include "qlistviewexplorermodel.h"

#include <QPixmap>

QListViewExplorerModel::QListViewExplorerModel(QObject *parent)
    :QAbstractListModel(parent)
{

}

void QListViewExplorerModel::getFolderList(QString folderPath, QFileInfoList *dirList)
{
    QDir dir = QDir(folderPath);

    *dirList = dir.entryInfoList(QDir::NoDot | QDir::Files | QDir::Dirs, QDir::DirsFirst);

    this->beginResetModel();
        this->aDirList = dirList;
    this->endResetModel();
}

int QListViewExplorerModel::rowCount(const QModelIndex &) const
{
    return this->aDirList->count();
}

QVariant QListViewExplorerModel::data( const QModelIndex &index, int role ) const
{

    QVariant value;

        switch ( role )
        {
            case Qt::DisplayRole: //string
            {
                value = this->aDirList->at(index.row()).fileName();
            }
            break;

            case Qt::DecorationRole: //icon
            {
                if (this->aDirList->at(index.row()).isDir()) {
                    QPixmap icon = QPixmap(":/img/folder.png");
                    QPixmap tmp = icon.scaled(30, 30, Qt::KeepAspectRatio);
                    value = tmp;
                    break;
                }

                if (this->aDirList->at(index.row()).isFile()) {
                    QString fileExt = this->aDirList->at(index.row()).completeSuffix();

                    if (fileExt == "zip") {

                        QPixmap icon = QPixmap(":/img/zip.png");
                        QPixmap tmp = icon.scaled(30, 30, Qt::KeepAspectRatio);
                        value = tmp;
                        break;

                    }

                    QPixmap icon = QPixmap(":/img/file.png");
                    QPixmap tmp = icon.scaled(30, 30, Qt::KeepAspectRatio);
                    value = tmp;
                    break;
                }

                value = this->aDirList->at(index.row()).fileName();
            }
            break;

            case Qt::UserRole: //data
            {
                value = this->aDirList->at(index.row()).fileName();
            }
            break;

            default:
                break;
        }

    return value;
}
