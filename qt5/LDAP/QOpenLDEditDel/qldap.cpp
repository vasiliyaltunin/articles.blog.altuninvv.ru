/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a GPLv3 
** license that can be found in the LICENSE file.
**
** Qldap - class for work with LDAP server via libldap (OpenLDAP) library.
**
****************************************************************************/

#include "qldap.h"
#include "QDebug"

#include <QTextCodec>


QLdap::QLdap()
{
    this->ldp = NULL;
}

int QLdap::init(const QString &url)
{

    int result;

    this->ldp = NULL;

    std::string str = url.toStdString();
    const char *aurl = str.c_str();
    result = ldap_create(&this->ldp);


    if ( result != LDAP_SUCCESS )
    {
        qCritical() << "ldap_create() error: " << ldap_err2string(result);
        return result;
    }

    if (url != NULL) {
        result = ldap_set_option(this->ldp, LDAP_OPT_URI, aurl);
        if ( result != LDAP_SUCCESS ) {
            qCritical() << "ldap_set_option() url error: " << ldap_err2string(result);
            return result;
        }
    }

    const int version = LDAP_VERSION3;

    result = ldap_set_option(this->ldp, LDAP_OPT_PROTOCOL_VERSION, &version);
    if ( result != LDAP_SUCCESS )
    {
        qCritical() << "ldap_set_option() ver LDAP_OPT_PROTOCOL_VERSION error: " << ldap_err2string(result);
    }

    const int reff = 0;
    ldap_set_option(this->ldp, LDAP_OPT_REFERRALS, &reff);
    if ( result != LDAP_SUCCESS )
    {
        qCritical() << "ldap_set_option() ref LDAP_OPT_REFERRALS error: " << ldap_err2string(result);
    }

    return LDAP_SUCCESS;
}

int QLdap::bind(const QString &dn,const QString &password)
{
    const char *adn;
    adn = (char*)dn.toStdString().c_str();

    berval *creds = new berval();

    creds->bv_val = (char*)password.toStdString().c_str();
    creds->bv_len = password.length();

    int result  = ldap_sasl_bind_s(this->ldp,
                                   adn,
                                   LDAP_SASL_SIMPLE,
                                   creds,
                                   nullptr,
                                   nullptr,
                                   nullptr);

    if ( result != LDAP_SUCCESS )
    {
        qCritical() << "ldap_sasl_bind_s() error: " << ldap_err2string(result);
    }
    return result;
}

int QLdap::close()
{
    int result = ldap_unbind_ext_s(this->ldp,nullptr,nullptr);
    if ( result != LDAP_SUCCESS )
    {
        qCritical() << "ldap_unbind_ext_s() error: " << ldap_err2string(result);
    }
    return result;
}


int QLdap::search(const QString &baseDN, const QString &filter, QLdapEntryList *searchResults, const QString &codePage)
{
    QTextCodec *codec = QTextCodec::codecForName(codePage.toUtf8());

    timeval	*timeout = new timeval();
    timeout->tv_sec = 100;

    LDAPMessage *searchResultMsg;

    int result  = ldap_search_ext_s( this->ldp,
                     (char*)baseDN.toStdString().c_str(),
                     LDAP_SCOPE_SUBTREE,
                     (char*)filter.toStdString().c_str(),
                     NULL,
                     0,
                     NULL,
                     NULL,
                     NULL,
                     LDAP_NO_LIMIT,
                     &searchResultMsg
                   );
    qDebug() << "Search result = " << ldap_err2string(result);

    if ( result != LDAP_SUCCESS )
    {
        qDebug() << "ldap_parse_result() error: " << ldap_err2string(result);
    }


    result = ldap_count_entries( this->ldp, searchResultMsg);
    qDebug() << "Search results count = " << result;

    result = ldap_count_references( this->ldp, searchResultMsg);
    qDebug() << "Search results ref = " << result;


    LDAPMessage *msg;

    QLdapEntryList results;


    for ( msg = ldap_first_message( this->ldp, searchResultMsg ); msg != NULL; msg = ldap_next_message( this->ldp, msg ) )
    {
        int msgtype = ldap_msgtype( msg );
        //qDebug() << "Type" << msgtype;

        switch( msgtype ) {

            //This is a search result data
            case LDAP_RES_SEARCH_RESULT:
            {

                //char *matched_msg = NULL;
                int errcodep = 0;
                char *error_msg = NULL;
                //char **refs;
                //LDAPControl **serverctrls;

                int aresult = ldap_parse_result( this->ldp,
                                                msg,
                                                &errcodep,
                                                NULL,
                                                &error_msg,
                                                NULL,
                                                NULL,
                                                0 );
                if ( aresult != LDAP_SUCCESS )
                {
                    qDebug() << "ldap_parse_result() error: " << ldap_err2string(aresult);
                }

                if ( errcodep != LDAP_SUCCESS )
                {
                    qDebug() << "ldap_parse_result() error: " << error_msg;
                }

                if (error_msg)
                {
                      ldap_memfree(error_msg);
                      return errcodep;
                }


                break;
            }

            //This is a data item of search
            case LDAP_RES_SEARCH_ENTRY:
            {
                BerElement *ber;
                char *a;

                QLdapEntry entry;

                for ( a = ldap_first_attribute( this->ldp, msg, &ber );
                      a != NULL;
                      a = ldap_next_attribute( this->ldp, msg, ber ) ) {



                    struct berval **values;
                    struct berval value;

                    //qDebug() << a;

                    if (( values = ldap_get_values_len( this->ldp, msg, a )) != NULL ) {

                        QLdapEntryValues attrvalues = QLdapEntryValues();

                        for ( int i = 0; values[ i ] != NULL; i++ ) {
                            value = *values[i];

                            QByteArray buf = value.bv_val;


                            QString text;
                            if (codePage.compare("utf-8") == 0) {
                                text = buf;
                            } else {
                                text  = codec->toUnicode(buf);
                            }


                            attrvalues.append(text);


//                            qDebug() << a << ":" << text;
                        }

                        entry.insert(a,attrvalues);
                        ldap_value_free_len( values );
                    }

                    ldap_memfree( a );
                }
                searchResults->append(entry);
                break;
            }
        }
    }

    ldap_msgfree(searchResultMsg);
    ldap_msgfree(msg);
    return LDAP_SUCCESS;
}


int QLdap::add(const QString &baseDN, QLdapEntry *entry, LDAPMod **mods)
{
    int result ;

    QString newdns = "CN=" + entry->value("name")[0] + "," + baseDN; //OU=Company,DC=altuninvv,DC=local";

    qDebug() << "new dn = " << newdns;

    char *newDN = _strdup(newdns.toStdString().c_str());

    result = ldap_add_ext_s( this->ldp, newDN, mods, NULL, NULL );

    free(newDN);

    qDebug() << "Added";

    return result;
}


int QLdap::del(const QString &baseDN)
{
    char *baseDNp = _strdup(baseDN.toStdString().c_str());

    qDebug() << "Delete DN = " << baseDN;

    int result = ldap_delete_ext_s( this->ldp, baseDNp, NULL, NULL );

    free(baseDNp);

    qDebug() << "Deleted";

    return result;
}

int QLdap::edit(const QString &baseDN, LDAPMod **mods)
{

    char *baseDNp = _strdup(baseDN.toStdString().c_str());

    qDebug() << "Edit DN = " << baseDN;

    int result = ldap_modify_ext_s( this->ldp, baseDNp, mods, NULL, NULL );

    free(baseDNp);

    qDebug() << "Edited";

    return result;
}
