/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Qldap - class for work with LDAP server via libldap (OpenLDAP) library.
**
****************************************************************************/

#ifndef QLDAP_H
#define QLDAP_H

#include "ldap.h"

#include <QString>
#include <QVariant>

typedef QStringList QLdapEntryValues;
typedef QHash<QString,QLdapEntryValues> QLdapEntry;
typedef QList<QLdapEntry> QLdapEntryList;

class QLdap
{
public:
    explicit QLdap();
    int init(const QString &url);
    int bind(const QString &dn, const QString &password);
    int close();
    int search(const QString &baseDN, const QString &filter, QLdapEntryList *searchResults, const QString &codePage="utf-8");
    int add(const QString &baseDN, QLdapEntry *entry, LDAPMod **mods);
private:
    LDAP *ldp;
};

#endif // QLDAP_H
