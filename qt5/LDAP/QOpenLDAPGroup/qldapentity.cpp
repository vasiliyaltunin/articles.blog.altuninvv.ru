/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3
** license that can be found in the LICENSE file.
**
** QLdapEntity - base class for all LDAP entry.
**
****************************************************************************/
#include "qldapentity.h"
#include <QDebug>

QLdapEntity::QLdapEntity(QLdapEntry *entry)
{
    this->entry = entry;
}

QString QLdapEntity::getEntityValue(const QString &key) const
{
        return (*this->entry)[key].join(",");
}

void QLdapEntity::setEntityValue(const QString &key, const QLdapEntryValues &value) const
{
        (*this->entry)[key] = value;
}

QString QLdapEntity::toString() const
{
    QString s;
    QTextStream out(&s);

    out << "QLdapEntity( ";
    for(QLdapEntry::iterator i=this->entry->begin();i!=this->entry->end();++i)
    {
        out << i.key() << ": " << i.value().join(",") << ", ";
    }
    out << " )";
    return s;
}


QDebug operator<<(QDebug debug, const QLdapEntity &entity)
{
    QDebugStateSaver saver(debug);


    debug.nospace() << "QLdapEntity( ";
    for(QLdapEntry::iterator i=entity.getEntry()->begin();i!=entity.getEntry()->end();++i)
    {
        debug.nospace() << i.key() << ": " << i.value().join(",") << ", ";
    }
    debug.nospace() << " )";

    return debug;
}


QDebug operator<<(QDebug debug, const QLdapEntity *entity)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << *entity;
    return debug;
}

QString QLdapEntity::operator[] (const QString &index) const
{
    assert(index.compare("") != 0);
    return this->getEntityValue(index);
}

QLdapEntry *QLdapEntity::getEntry() const
{
    return entry;
}
