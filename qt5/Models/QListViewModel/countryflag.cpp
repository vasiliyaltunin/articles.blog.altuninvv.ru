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
** CountryFlag - storage class for QComboBox data
**
****************************************************************************/

#include "countryflag.h"

CountryFlag::CountryFlag()
{

}

CountryFlag::CountryFlag(int id, QString name, QString icon)
{
    this->id = id;
    this->name = name;
    this->icon = icon;
}

QString CountryFlag::getName() const
{
    return name;
}

void CountryFlag::setName(const QString &value)
{
    name = value;
}

int CountryFlag::getId() const
{
    return id;
}

void CountryFlag::setId(int value)
{
    id = value;
}

QString CountryFlag::getCapital() const
{
    return capital;
}

void CountryFlag::setCapital(const QString &value)
{
    capital = value;
}

QString CountryFlag::getIcon() const
{
    return icon;
}

void CountryFlag::setIcon(const QString &value)
{
    icon = value;
}
