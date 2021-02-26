/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3
** license that can be found in the LICENSE file.
**
** QLdapMod - class for data exchange with LDAP server via libldap (OpenLDAP)
** library.
**
** Based on https://docs.oracle.com/cd/E19957-01/817-6707/addmod.html#wp32651
**
****************************************************************************/

#ifndef QLDAPMOD_H
#define QLDAPMOD_H

#include "qldap.h"
#include "QDebug"


typedef LDAPMod *LdapMod;

class QLdapMod
{
public:
    explicit QLdapMod(QLdapEntry *entry, const int &opMod);
    ~QLdapMod();
    LDAPMod **getMods();

private:
    LDAPMod **mods;
    QLdapEntry *entry;
    int opMode = LDAP_MOD_ADD;
};

#endif // QLDAPMOD_H
