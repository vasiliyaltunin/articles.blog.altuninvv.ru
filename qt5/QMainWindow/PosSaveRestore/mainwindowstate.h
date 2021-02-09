/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3
** license that can be found in the LICENSE file.
**
** MainWindowState - class to save\restore MainWindows state (position
** and size) with QSettings.
**
****************************************************************************/

#ifndef MAINWINDOWSTATE_H
#define MAINWINDOWSTATE_H

#include <QPoint>
#include <QSize>


class MainWindowState
{
public:
    explicit MainWindowState();
    void SaveState(const QPoint &pos, const QSize &size);
    void RestoreState(QPoint &pos, QSize &size);
};

#endif // MAINWINDOWSTATE_H
