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

#ifndef QLDAPGROUP_H
#define QLDAPGROUP_H

#include <QString>
#include "qldap.h"

class QLdapGroup
{
public:
    QLdapGroup(QLdapEntry *group);


    QString getValue(QString key) const;

    QStringList getMembers() const;

    QString getDN() const;
private:
    QLdapEntry *group;
};

#endif // QLDAPGROUP_H
