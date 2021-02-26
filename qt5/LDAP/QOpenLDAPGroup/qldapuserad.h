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

#ifndef QLDAPUSERAD_H
#define QLDAPUSERAD_H

#include "qldapuser.h"

class QLdapUserAD : public QLdapUser
{
public:
    explicit QLdapUserAD(QLdapEntry *user);
};

QDebug operator<<(QDebug debug, const QLdapUserAD &user);
QDebug operator<<(QDebug debug, const QLdapUserAD *user);


#endif // QLDAPUSERAD_H
