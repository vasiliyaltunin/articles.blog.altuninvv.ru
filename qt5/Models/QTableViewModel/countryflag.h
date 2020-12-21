/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how to extend model with class to use with model with QComboBox widget in Qt5
**
** CountryFlag - storage class for QTableView data
**
****************************************************************************/

#ifndef COUNTRYFLAG_H
#define COUNTRYFLAG_H

#include <QString>



class CountryFlag
{
public:
    CountryFlag();
    CountryFlag(int id, QString name, QString icon);
    QString getIcon() const;
    void setIcon(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    int getId() const;
    void setId(int value);

private:
    int id;
    QString icon;
    QString name;
};

#endif // COUNTRYFLAG_H
