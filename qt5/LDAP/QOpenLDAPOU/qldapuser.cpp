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
#include "qldapuser.h"
#include <QDebug>
#include <QString>

QLdapUser::QLdapUser(QLdapEntry *user) : QLdapEntity(user)
{
}

QString QLdapUser::getDisplayName() const
{
    return this->getEntityValue("displayName");
}


QString QLdapUser::getInitials() const
{
    return this->getEntityValue("initials");
}


QString QLdapUser::getOfficePhone() const
{
    return this->getEntityValue("otherTelephone");
}

QString QLdapUser::getDepartment() const
{
    return this->getEntityValue("department");
}


QString QLdapUser::getTitle() const
{
    return this->getEntityValue("title");
}

QString QLdapUser::getUserPrincipalName() const
{
    return this->getEntityValue("userPrincipalName");
}


QString QLdapUser::getCellPhone() const
{
    return this->getEntityValue("mobile");
}

QString QLdapUser::getSamAccountName() const
{
    return this->getEntityValue("sAMAccountName");
}


QString QLdapUser::getPath() const
{
    return this->getEntityValue("distinguishedName");
}

QString QLdapUser::getEmail() const
{
    return this->getEntityValue("mail");
}

QString QLdapUser::getStreetAddress() const
{
    return this->getEntityValue("streetAddress");
}

QString QLdapUser::getOffice() const
{
    return this->getEntityValue("physicalDeliveryOfficeName");
}

QString QLdapUser::getCompany() const
{
    return this->getEntityValue("company");
}

QString QLdapUser::getFax() const
{
    return this->getEntityValue("facsimileTelephoneNumber");
}




void QLdapUser::setDisplayName(const QString &value) const
{

    this->setEntityValue("displayName",QStringList(value));
}

void QLdapUser::setGivenName(const QString &value) const
{
    this->setEntityValue("givenName",QStringList(value));
}

void QLdapUser::setInitials(const QString &value) const
{
    this->setEntityValue("initials",QStringList(value));
}

void QLdapUser::setOfficePhone(const QString &value) const
{
    this->setEntityValue("otherTelephone",QStringList(value));
}

void QLdapUser::setDepartment(const QString &value) const
{
    this->setEntityValue("department",QStringList(value));
}

void QLdapUser::setTitle(const QString &value) const
{
    this->setEntityValue("title",QStringList(value));
}

void QLdapUser::setUserPrincipalName(const QString &value) const
{
    this->setEntityValue("userPrincipalName",QStringList(value));
}

void QLdapUser::setMobilePhone(const QString &value) const
{
    this->setEntityValue("mobile",QStringList(value));
}

void QLdapUser::setSamAccountName(const QString &value) const
{
    this->setEntityValue("sAMAccountName",QStringList(value));
}

void QLdapUser::setPath(const QString &value) const
{
    this->setEntityValue("distinguishedName",QStringList(value));
}

void QLdapUser::setEmail(const QString &value) const
{
    this->setEntityValue("mail",QStringList(value));
}

void QLdapUser::setStreetAddress(const QString &value) const
{
    this->setEntityValue("streetAddress",QStringList(value));
}

void QLdapUser::setOffice(const QString &value) const
{
    this->setEntityValue("physicalDeliveryOfficeName",QStringList(value));
}

void QLdapUser::setCompany(const QString &value) const
{
    this->setEntityValue("company",QStringList(value));
}

void QLdapUser::setFax(const QString &value) const
{
    this->setEntityValue("facsimileTelephoneNumber",QStringList(value));
}

void QLdapUser::setName(const QString &value) const
{
    this->setEntityValue("name",QStringList(value));
}

QDebug operator<<(QDebug debug, const QLdapUser &user)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << "QLdapUserAD( ";
    debug.nospace() << (QLdapEntity *)&user;
    debug.nospace() << " )";
    return debug;
}

QDebug operator<<(QDebug debug, const QLdapUser *user)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << *user;
    return debug;
}
