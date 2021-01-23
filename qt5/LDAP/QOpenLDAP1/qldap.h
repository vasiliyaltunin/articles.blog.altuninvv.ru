#ifndef QLDAP_H
#define QLDAP_H

#include "ldap.h"

#include <QString>

class QLdap
{
public:
    QLdap();
    int init(const QString url);
    int bind(QString dn, QString password);
    int close();
private:
    LDAP *ldp;
};

#endif // QLDAP_H
