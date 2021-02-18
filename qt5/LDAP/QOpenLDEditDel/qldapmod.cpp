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

#include "qldapmod.h"

QLdapMod::QLdapMod(QLdapEntry *entry, const int &opMod)
{
    this->entry = entry;
    this->opMode = opMod;

    int nonEmptyRecords = 0;
    for(QLdapEntry::iterator i=this->entry->begin();i!=this->entry->end();++i)
    {
        if ((!i.value().join(",").isEmpty()) && (i.key().compare("operation") != 0))
        {
            nonEmptyRecords++;
        }

    }

    mods = (LDAPMod**) malloc( (nonEmptyRecords+1) * sizeof(LDAPMod*) );

    int j = 0;
    for(QLdapEntry::iterator i=this->entry->begin();i!=this->entry->end();++i)
    {
        if (!i.value().join(",").isEmpty())
        {
            if ((mods[j]=(LDAPMod *) malloc(sizeof(LDAPMod))) == NULL )
            {
                fprintf( stderr, "Cannot allocate memory for mods element\n" );
                exit( 1 );
            }
            j++;
        }
    }


}

QLdapMod::~QLdapMod()
{
    int j = 0;
    for(QLdapEntry::iterator i=this->entry->begin();i!=this->entry->end();++i)
    {
        if (!i.value().join(",").isEmpty())
        {
            free(mods[j]->mod_type);
            free(mods[j]->mod_vals.modv_strvals);
            free(mods[j]);
            j++;
        }

    }
    free(mods);
}

void setCharArrayFromQstringList(const QStringList &value, char **c)
{
    for (int i=0; i < value.count(); i++)
    {
        c[i] = _strdup(value[i].toStdString().c_str());
    }

    c[value.count()] = NULL;
}

LDAPMod **QLdapMod::getMods()
{
    qDebug() << "GetMods";


    qDebug() << "OP: " << this->opMode;

    int j = 0;
    for(QLdapEntry::iterator i=this->entry->begin();i!=this->entry->end();++i)
    {
        if (!i.value().join(",").isEmpty())
        {
            mods[j]->mod_op = this->opMode;

            mods[j]->mod_type = _strdup(i.key().toStdString().c_str());

            mods[j]->mod_values = new char*[i.value().count()+1];            

            setCharArrayFromQstringList(i.value(),mods[j]->mod_values);
            j++;
        }
    }

    mods[j] = NULL;

    return mods;
}
