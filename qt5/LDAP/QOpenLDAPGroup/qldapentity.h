/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3
** license that can be found in the LICENSE file.
**
** QLdapEntity - base class for all LDAP entry.
**
****************************************************************************/
#ifndef QLDAPENTITY_H
#define QLDAPENTITY_H

#include <QString>
#include "qldap.h"



class QLdapEntity
{
public:
    explicit QLdapEntity(QLdapEntry *entry);
    QString getEntityValue(const QString &key) const;
    void setEntityValue(const QString &key, const QLdapEntryValues &value) const;

    QString toString() const;
    QString operator [](const QString &index) const;
    QLdapEntry *getEntry() const;
private:
    QLdapEntry *entry;
};

QDebug operator<<(QDebug debug, const QLdapEntity &entity);
QDebug operator<<(QDebug debug, const QLdapEntity *entity);


#endif // QLDAPENTITY_H
