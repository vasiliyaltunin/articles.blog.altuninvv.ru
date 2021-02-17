#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ldap.h"
#include "qldap.h"
#include "QDebug"
#include "qldapuser.h"
#include "qldapsearch.h"
#include "qldapmod.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLdap *ldap = new QLdap();

    const QString url= "ldap://192.168.130.233:389";

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



    QLdapEntry *user = new QLdapEntry();
    QLdapUser u = QLdapUser(user);

    u.setDisplayName("Иванов Иван Иванович");

    u.setTitle("Бухгалтер");

    u.setGivenName("Иванов И. И.");

    u.setName("Иванов И. И.");

    u.setInitials("И.");
    u.setDepartment("Бухгалтерия");
    u.setEmail("IvanovII@altuninvv.local");
    u.setStreetAddress("Ленина 1");
    u.setOffice("104");
    u.setCompany("Altunin Soft");

    u.setOfficePhone("+7(495)12300024");
    u.setMobilePhone("+7(495)876-16-18");
    u.setFax("");
    u.setUserValue("objectClass",QStringList({"user","person","top","organizationalPerson"}));


    qDebug() << u;
    qDebug() << user->values();
    qDebug() << user->keys();



    QLdapMod *mod = new QLdapMod(user);

    LDAPMod **m = mod->getMods();

    result = ldap->add("OU=Company,DC=altuninvv,DC=local", user, m);

    delete mod;

    if ( result != LDAP_SUCCESS )
    {
        QString msg = QString("QLDAP add() error: ") + QString(ldap_err2string(result));
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

