#ifndef QLDAP_H
#define QLDAP_H

#include "ldap.h"

#include <QString>
#include <QVariant>

typedef QHash<QString, QVariant> QLdapEntry;
typedef QList<QLdapEntry> QLdapEntryList;

class QLdap
{
public:
    QLdap();
    int init(const QString url);
    int bind(QString dn, QString password);
    int close();
    int search(QString baseDN, QString filter, QLdapEntryList *searchResults, const QString codePage="utf-8");
private:
    LDAP *ldp;
};

#endif // QLDAP_H
