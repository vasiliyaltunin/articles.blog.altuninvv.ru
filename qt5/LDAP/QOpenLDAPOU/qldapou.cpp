/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3
** license that can be found in the LICENSE file.
**
** QLdapOU - class for work with LDAP OU.
**
****************************************************************************/

#include "qldapou.h"
#include <QDebug>

QLdapOU::QLdapOU(QLdapEntry *ou) : QLdapEntity(ou)
{
    this->setEntityValue("objectClass",QStringList({"organizationalUnit"}));
}


QString QLdapOU::getDecription() const
{
    return this->getEntityValue("description");
}

void QLdapOU::setDecription(const QString &value) const
{

    this->setEntityValue("description",QStringList(value));
}


void QLdapOU::setName(const QString &value) const
{
    this->setEntityValue("name",QStringList(value));
}

QString QLdapOU::getName() const
{
    return this->getEntityValue("name");
}

QDebug operator<<(QDebug debug, const QLdapOU &user)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << "QLdapOU( ";
    debug.nospace() << (QLdapEntity *)&user;
    debug.nospace() << " )";
    return debug;
}

QDebug operator<<(QDebug debug, const QLdapOU *user)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << *user;
    return debug;
}
