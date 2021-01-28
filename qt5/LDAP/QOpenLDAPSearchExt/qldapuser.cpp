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

QString QLdapUser::getUserValue(QString key) const
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

