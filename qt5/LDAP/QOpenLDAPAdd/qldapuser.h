/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** QLdapUser - class for work with LDAP Users.
**
****************************************************************************/

#ifndef QLDAPUSER_H
#define QLDAPUSER_H

#include <QString>
#include "qldap.h"



class QLdapUser
{
public:
    explicit QLdapUser();

    explicit QLdapUser(QLdapEntry *user);

    QString getDisplayName() const;

    QString getGivenName() const;

    QString getInitials() const;

    QString getOfficePhone() const;

    QString getDepartment() const;

    QString getTitle() const;

    QString getUserPrincipalName() const;

    QString getCellPhone() const;

    QString getSamAccountName() const;

    QString getPath() const;

    QString getEmail() const;

    QString getStreetAddress() const;

    QString getOffice() const;

    QString getCompany() const;

    QString getFax() const;

    QString getUserValue(const QString &key) const;



    void setUserValue(const QString &key, const QLdapEntryValues &value) const;

    void setDisplayName(const QString &value) const;

    void setGivenName(const QString &value) const;

    void setInitials(const QString &value) const;

    void setOfficePhone(const QString &value) const;

    void setDepartment(const QString &value) const;

    void setTitle(const QString &value) const;

    void setUserPrincipalName(const QString &value) const;

    void setMobilePhone(const QString &value) const;

    void setSamAccountName(const QString &value) const;

    void setPath(const QString &value) const;

    void setEmail(const QString &value) const;

    void setStreetAddress(const QString &value) const;

    void setOffice(const QString &value) const;

    void setCompany(const QString &value) const;

    void setFax(const QString &value) const;

    void setName(const QString &value) const;




    QString toString() const;

    QString operator [](const QString &index) const;
private:

    QLdapEntry *user;
};

QDebug operator<<(QDebug debug, const QLdapUser &user);
QDebug operator<<(QDebug debug, const QLdapUser *user);

#endif // QLDAPUSER_H

