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

#ifndef QLDAPOU_H
#define QLDAPOU_H

#include <QString>
#include "qldap.h"
#include "qldapentity.h"


class QLdapOU : public QLdapEntity
{
public:
    explicit QLdapOU(QLdapEntry *ou);

    void setDecription(const QString &value) const;
    QString getDecription() const;

    void setName(const QString &value) const;
    QString getName() const;
};


QDebug operator<<(QDebug debug, const QLdapOU &user);
QDebug operator<<(QDebug debug, const QLdapOU *user);

#endif // QLDAPOU_H
