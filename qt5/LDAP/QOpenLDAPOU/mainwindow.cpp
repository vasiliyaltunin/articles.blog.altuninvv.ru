#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ldap.h"
#include "qldap.h"
#include "QDebug"
#include "qldapuser.h"
#include "qldapsearch.h"
#include "qldapmod.h"
#include "qldapuserad.h"
#include "qldapou.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLdap *ldap = new QLdap();

    const QString url= "ldap://192.168.0.10:389";

    int result;

    result = ldap->init(url);
    if ( result != LDAP_SUCCESS )
    {
        QString msg = QString("QLDAP init() error: ") + QString(ldap_err2string(result));
        qFatal("%s",msg.toLatin1().constData());
    }

    qDebug() << "Init result = " << ldap_err2string(result);

    result = ldap->bind("CN=ldap-bind,CN=Users,DC=altuninvv,DC=local", "Pas#w0rds#1");

    if ( result != LDAP_SUCCESS )
    {
        QString msg = QString("QLDAP bind() error: ") + QString(ldap_err2string(result));
        ldap->close();
        qFatal("%s",msg.toLatin1().constData());
    }

    qDebug() << "Bind result = " << ldap_err2string(result);


    result = ldap->del("ou=otdel5,OU=Company,DC=altuninvv,DC=local");

    if ( result != LDAP_SUCCESS )
    {
        QString msg = QString("QLDAP OU del() error: ") + QString(ldap_err2string(result));
        qDebug("%s",msg.toLatin1().constData());
        //return;
    }

    QLdapEntry *ou1 = new QLdapEntry();
    QLdapOU ou = QLdapOU(ou1);

    ou.setName("otdel5");
    ou.setDecription("Отдел №5");

    qDebug() << ou;

    QLdapMod *mod2 = new QLdapMod(ou1, LDAP_MOD_ADD);
    LDAPMod **m2 = mod2->getMods();

    result = ldap->add("OU=Company,DC=altuninvv,DC=local", ou1, m2);

    delete mod2;

    if ( result != LDAP_SUCCESS )
    {
        QString msg = QString("QLDAP ou add() error: ") + QString(ldap_err2string(result));
        qDebug("%s",msg.toLatin1().constData());
        //return;
    }


    QLdapEntry *oue = new QLdapEntry();
      QLdapOU ou2 = QLdapOU(oue);
      ou2.setDecription("Новый Отдел №5");

      QLdapMod *mod1 = new QLdapMod(oue, LDAP_MOD_REPLACE);
      LDAPMod **m1 = mod1->getMods();

      result = ldap->edit("ou=otdel5,OU=Company,DC=altuninvv,DC=local", m1);

      delete mod1;

    //Close
    result = ldap->close();
    if ( result != LDAP_SUCCESS )
    {
        QString msg = QString("QLDAP init() error: ") + QString(ldap_err2string(result));
        qFatal("%s",msg.toLatin1().constData());
        //return;
    }
    qDebug() << "Close result = " << ldap_err2string(result);
    delete ldap;



     return;

}

MainWindow::~MainWindow()
{
    delete ui;
}

