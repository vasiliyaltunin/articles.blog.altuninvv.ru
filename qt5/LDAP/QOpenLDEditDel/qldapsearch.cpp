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

#include "qldapsearch.h"
#include <QDebug>

QLdapSearch::QLdapSearch(QLdap *ldap)
{
    this->ldap = ldap;
}

int QLdapSearch::user(const QString &filter)
{
    this->results->clear();
    QString aFilter = "(&(objectCategory=person)" + filter + ")";
    qDebug() << aFilter;
    return this->ldap->search(this->searchDN,
                 aFilter,
                 this->results);
}

int QLdapSearch::userByName(const QString &name)
{
    return this->user("(displayName=" + name + ")");
}

int QLdapSearch::userByLogin(const QString &login)
{
    return this->user("(sAMAccountName=" + login + ")");
}



void QLdapSearch::setDN(const QString &value)
{
    searchDN = value;
}

void QLdapSearch::setResult(QLdapEntryList *value)
{
    results = value;
}

QLdapEntryList *QLdapSearch::getResult() const
{
    return results;
}
