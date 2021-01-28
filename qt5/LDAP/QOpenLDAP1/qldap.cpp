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


QLdap::QLdap()
{

}

int QLdap::init(const QString url)
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

int QLdap::bind(QString dn, QString password)
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
