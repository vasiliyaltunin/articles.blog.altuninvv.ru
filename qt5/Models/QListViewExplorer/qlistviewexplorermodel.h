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

#ifndef QLISTVIEWEXPLORERMODEL_H
#define QLISTVIEWEXPLORERMODEL_H

#include <QDir>
#include <QModelIndex>

class QListViewExplorerModel: public QAbstractListModel
{
public:
    QListViewExplorerModel(QObject *parent=nullptr);
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;

    void getFolderList(QString folderPath, QFileInfoList *dirList);

private:
    QFileInfoList *aDirList;

};

#endif // QLISTVIEWEXPLORERMODEL_H
