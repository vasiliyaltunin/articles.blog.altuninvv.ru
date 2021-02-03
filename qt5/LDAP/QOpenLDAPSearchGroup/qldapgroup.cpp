/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** QLdapGroup - class for work with LDAP Groups.
**
****************************************************************************/

#include "qldapgroup.h"

QLdapGroup::QLdapGroup(QLdapEntry *group)
{
    this->group = group;
}

QStringList  QLdapGroup::getMembers() const
{
    return (*this->group)["member"].join(",").split(",");
}

QString QLdapGroup::getValue(QString key) const
{
    return (*this->group)[key].join(",");
}

QString  QLdapGroup::getDN() const
{
    return (*this->group)["distinguishedName"].join(",");
}


