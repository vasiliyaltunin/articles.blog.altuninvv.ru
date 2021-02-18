/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** QLdapSearch - helper class for easy search on LDAP server.
**
****************************************************************************/

#ifndef QLDAPSEARCH_H
#define QLDAPSEARCH_H

#include "qldap.h"



class QLdapSearch
{
public:
    QLdapSearch(QLdap *ldap);

    int user(const QString &filter);
    void setDN(const QString &value);

    void setResult(QLdapEntryList *value);

    QLdapEntryList *getResult() const;

    int userByName(const QString &name);
    int userByLogin(const QString &login);
private:
    QLdap *ldap;
    QString searchDN;
    QLdapEntryList *results;

};

#endif // QLDAPSEARCH_H
