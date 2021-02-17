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
#include "qldapuser.h"
#include <QDebug>
#include <QString>

QLdapUser::QLdapUser()
{

}

QLdapUser::QLdapUser(QLdapEntry *user)
{
    this->user = user;
}

QString QLdapUser::getUserValue(const QString &key) const
{
        return (*this->user)[key].join(",");
}

QString QLdapUser::getDisplayName() const
{
    return this->getUserValue("displayName");
}


QString QLdapUser::getInitials() const
{
    return this->getUserValue("initials");
}


QString QLdapUser::getOfficePhone() const
{
    return this->getUserValue("otherTelephone");
}

QString QLdapUser::getDepartment() const
{
    return this->getUserValue("department");
}


QString QLdapUser::getTitle() const
{
    return this->getUserValue("title");
}

QString QLdapUser::getUserPrincipalName() const
{
    return this->getUserValue("userPrincipalName");
}


QString QLdapUser::getCellPhone() const
{
    return this->getUserValue("mobile");
}

QString QLdapUser::getSamAccountName() const
{
    return this->getUserValue("sAMAccountName");
}


QString QLdapUser::getPath() const
{
    return this->getUserValue("distinguishedName");
}

QString QLdapUser::getEmail() const
{
    return this->getUserValue("mail");
}

QString QLdapUser::getStreetAddress() const
{
    return this->getUserValue("streetAddress");
}

QString QLdapUser::getOffice() const
{
    return this->getUserValue("physicalDeliveryOfficeName");
}

QString QLdapUser::getCompany() const
{
    return this->getUserValue("company");
}

QString QLdapUser::getFax() const
{
    return this->getUserValue("facsimileTelephoneNumber");
}

void QLdapUser::setUserValue(const QString &key, const QLdapEntryValues &value) const
{
        (*this->user)[key] = value;
}

void QLdapUser::setDisplayName(const QString &value) const
{

    this->setUserValue("displayName",QStringList(value));
}

void QLdapUser::setGivenName(const QString &value) const
{
    this->setUserValue("givenName",QStringList(value));
}

void QLdapUser::setInitials(const QString &value) const
{
    this->setUserValue("initials",QStringList(value));
}

void QLdapUser::setOfficePhone(const QString &value) const
{
    this->setUserValue("otherTelephone",QStringList(value));
}

void QLdapUser::setDepartment(const QString &value) const
{
    this->setUserValue("department",QStringList(value));
}

void QLdapUser::setTitle(const QString &value) const
{
    this->setUserValue("title",QStringList(value));
}

void QLdapUser::setUserPrincipalName(const QString &value) const
{
    this->setUserValue("userPrincipalName",QStringList(value));
}

void QLdapUser::setMobilePhone(const QString &value) const
{
    this->setUserValue("mobile",QStringList(value));
}

void QLdapUser::setSamAccountName(const QString &value) const
{
    this->setUserValue("sAMAccountName",QStringList(value));
}

void QLdapUser::setPath(const QString &value) const
{
    this->setUserValue("distinguishedName",QStringList(value));
}

void QLdapUser::setEmail(const QString &value) const
{
    this->setUserValue("mail",QStringList(value));
}

void QLdapUser::setStreetAddress(const QString &value) const
{
    this->setUserValue("streetAddress",QStringList(value));
}

void QLdapUser::setOffice(const QString &value) const
{
    this->setUserValue("physicalDeliveryOfficeName",QStringList(value));
}

void QLdapUser::setCompany(const QString &value) const
{
    this->setUserValue("company",QStringList(value));
}

void QLdapUser::setFax(const QString &value) const
{
    this->setUserValue("facsimileTelephoneNumber",QStringList(value));
}

void QLdapUser::setName(const QString &value) const
{
    this->setUserValue("name",QStringList(value));
}


QString QLdapUser::toString() const
{
    QString s;
    QTextStream out(&s);

    out << "QLdapUser( "
        << "displayName: " << this->getDisplayName() << ","
        << "initials: " << this->getInitials() << ","
        << "officePhone: " << this->getOfficePhone() << ","
        << "department: " << this->getDepartment() << ","
        << "title: " << this->getTitle() << ","
        << "userPrincipalName: " << this->getUserPrincipalName() << ","
        << "cellPhone: " << this->getCellPhone() << ","
        << "samAccountName: " << this->getSamAccountName() << ","
        << "path: " << this->getPath() << ","
        << "email: " << this->getEmail() << ","
        << "streetAddress: " << this->getStreetAddress() << ","
        << "office: " << this->getOffice() << ","
        << "company: " << this->getCompany() << ","
        << "fax: " << this->getFax() << ""
        << " )"
        ;
    return s;
}


QDebug operator<<(QDebug debug, const QLdapUser &user)
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "QLdapUser( "
        << "displayName: " << user.getDisplayName() << ", "
        << "initials: " << user.getInitials() << ", "
        << "officePhone: " << user.getOfficePhone() << ", "
        << "department: " << user.getDepartment() << ", "
        << "title: " << user.getTitle() << ", "
        << "userPrincipalName: " << user.getUserPrincipalName() << ", "
        << "cellPhone: " << user.getCellPhone() << ", "
        << "samAccountName: " << user.getSamAccountName() << ", "
        << "path: " << user.getPath() << ", "
        << "email: " << user.getEmail() << ", "
        << "streetAddress: " << user.getStreetAddress() << ", "
        << "office: " << user.getOffice() << ", "
        << "company: " << user.getCompany() << ", "
        << "fax: " << user.getFax() << ""
        << " )";
    return debug;
}


QDebug operator<<(QDebug debug, const QLdapUser *user)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << *user;
    return debug;
}

QString QLdapUser::operator[] (const QString &index) const
{
    assert(index.compare("") != 0);
    return this->getUserValue(index);
}
