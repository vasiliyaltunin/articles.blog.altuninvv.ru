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
#include <QtDebug>

QLdapGroup::QLdapGroup(QLdapEntry *group) : QLdapEntity(group)
{
}

QStringList  QLdapGroup::getMembers() const
{
    return this->getEntry()->value("member");
}

QString QLdapGroup::getValue(QString key) const
{
    return this->getEntry()->value(key).join(",");
}

QString  QLdapGroup::getDN() const
{
    return this->getEntry()->value("distinguishedName").join(",");
}

QDebug operator<<(QDebug debug, const QLdapGroup &user)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << "QLdapGroup( ";
    debug.nospace() << (QLdapEntity *)&user;
    debug.nospace() << " )";
    return debug;
}

QDebug operator<<(QDebug debug, const QLdapGroup *user)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << *user;
    return debug;
}


