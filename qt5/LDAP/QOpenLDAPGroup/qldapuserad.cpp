/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3
** license that can be found in the LICENSE file.
**
** QLdapUser - class for work with AD LDAP Users.
**
****************************************************************************/

#include "qldapuserad.h"
#include <QDebug>

QLdapUserAD::QLdapUserAD(QLdapEntry *user) : QLdapUser(user)
{
    this->setEntityValue("objectClass",QStringList({"user","person","top","organizationalPerson"}));
}

QDebug operator<<(QDebug debug, const QLdapUserAD &user)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << "QLdapUserAD( ";
    debug.nospace() << (QLdapEntity *)&user;
    debug.nospace() << " )";
    return debug;
}

QDebug operator<<(QDebug debug, const QLdapUserAD *user)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << *user;
    return debug;
}
