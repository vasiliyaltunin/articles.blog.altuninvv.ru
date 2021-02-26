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
#include "qldapgroup.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLdap *ldap = new QLdap();

    const QString url= "ldap://192.168.0.1:389";

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


    result = ldap->del("cn=gg-it-otdel,OU=Company,DC=altuninvv,DC=local");

    if ( result != LDAP_SUCCESS )
    {
        QString msg = QString("QLDAP group del() error: ") + QString(ldap_err2string(result));
        qDebug("%s",msg.toLatin1().constData());
        //return;
    }

    QLdapEntry *e1 = new QLdapEntry();
    QLdapGroup grp = QLdapGroup(e1);

    grp.setName("gg-it-otdel");
    grp.setDescription("Группа для IT");

    qDebug() << grp;

    QLdapMod *mod1 = new QLdapMod(e1, LDAP_MOD_ADD);
    LDAPMod **m1 = mod1->getMods();

    result = ldap->add("OU=Company,DC=altuninvv,DC=local", e1, m1);

    delete mod1;

    if ( result != LDAP_SUCCESS )
    {
        QString msg = QString("QLDAP group add() error: ") + QString(ldap_err2string(result));
        qDebug("%s",msg.toLatin1().constData());
        //return;
    }

    QLdapEntry *e2 = new QLdapEntry();
    QLdapGroup grp2 = QLdapGroup(e2);
    grp2.setDescription("Новая группа для IT");

    QLdapMod *mod2 = new QLdapMod(e2, LDAP_MOD_REPLACE);
    LDAPMod **m2 = mod2->getMods();

    result = ldap->edit("ou=gg-it-otdel,OU=Company,DC=altuninvv,DC=local", m2);

    delete mod2;

    if ( result != LDAP_SUCCESS )
    {
        QString msg = QString("QLDAP group edit() error: ") + QString(ldap_err2string(result));
        qDebug("%s",msg.toLatin1().constData());
        //return;
    }

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

