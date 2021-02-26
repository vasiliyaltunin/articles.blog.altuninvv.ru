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
    explicit QLdapGroup(QLdapEntry *group);

    QStringList getMembers() const;

    QString getDN() const;

    void setDescription(const QString &value) const;
    QString getDescription() const;

    void setName(const QString &value) const;
    QString getName() const;


private:
};

QDebug operator<<(QDebug debug, const QLdapGroup &user);
QDebug operator<<(QDebug debug, const QLdapGroup *user);

#endif // QLDAPGROUP_H
