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
#include "qldapentity.h"

class QLdapGroup : public QLdapEntity
{
public:
    QLdapGroup(QLdapEntry *group);


    QString getValue(QString key) const;

    QStringList getMembers() const;

    QString getDN() const;
private:
};

QDebug operator<<(QDebug debug, const QLdapGroup &user);
QDebug operator<<(QDebug debug, const QLdapGroup *user);

#endif // QLDAPGROUP_H
