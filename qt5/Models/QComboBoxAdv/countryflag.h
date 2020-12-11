/****************************************************************************
**
** Copyright 2020 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** Example how to use delegate with model with QComboBox widget in Qt5
**
** CountryFlag - storage class for QComboBox data
**
****************************************************************************/

#ifndef COUNTRYFLAG_H
#define COUNTRYFLAG_H

#include <QString>



class CountryFlag
{
public:
    CountryFlag();
    CountryFlag(int id, QString name, QString capital);

    QString getName() const;
    void setName(const QString &value);

    int getId() const;
    void setId(int value);

    QString getCapital() const;
    void setCapital(const QString &value);

private:
    int id;
    QString name;
    QString capital;
};

#endif // COUNTRYFLAG_H
