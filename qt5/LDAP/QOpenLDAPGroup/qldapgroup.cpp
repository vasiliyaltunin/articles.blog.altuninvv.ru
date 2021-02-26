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
    this->setEntityValue("objectClass",QStringList({"group"}));
}

QStringList  QLdapGroup::getMembers() const
{
    return this->getEntityValue("member").split(",");
}

QString QLdapGroup::getDN() const
{
    return this->getEntityValue("distinguishedName");
}

void QLdapGroup::setDescription(const QString &value) const
{
    this->setEntityValue("description",QStringList(value));
}

QString QLdapGroup::getDescription() const
{
    return this->getEntityValue("description");
}

void QLdapGroup::setName(const QString &value) const
{
    this->setEntityValue("name",QStringList(value));
}

QString QLdapGroup::getName() const
{
    return this->getEntityValue("name");
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
