#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ldap.h"
#include "qldap.h"
#include "QDebug"
#include "qldapuser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLdap *ldap = new QLdap();

     const QString url= "ldap://192.168.0.1:389";

     int result = ldap->init(url);
     if ( result != LDAP_SUCCESS )
     {
         QString msg = QString("QLDAP init() error: ") + QString(ldap_err2string(result));
         qFatal("%s",msg.toLatin1().constData());
         return;
     }

     qDebug() << "Init result = " << ldap_err2string(result);

     result = ldap->bind("CN=ldap-bind,CN=Users,DC=altuninvv,DC=local", "Pas#w0rds#1");

     if ( result != LDAP_SUCCESS )
     {

         QString msg = QString("QLDAP bind() error: ") + QString(ldap_err2string(result));
         qFatal("%s",msg.toLatin1().constData());
         ldap->close();
         return;
     }

     qDebug() << "Bind result = " << ldap_err2string(result);


     QLdapEntryList *searchResults = new QLdapEntryList();

     int searchResult = ldap->search("OU=Company,DC=altuninvv,DC=local",
                  "(&(objectCategory=person))",
                  searchResults);

     if ( searchResult != LDAP_SUCCESS )
     {
         ldap->close();
         return;
     }

     result = ldap->close();
     if ( result != LDAP_SUCCESS )
     {
         QString msg = QString("QLDAP init() error: ") + QString(ldap_err2string(result));
         qFatal("%s",msg.toLatin1().constData());
         return;
     }

     qDebug() << "Close result = " << ldap_err2string(result);

     for( auto e = searchResults->begin(); e != searchResults->end(); ++e)
     {
         qDebug() << e->find("displayName").value() << e->find("title").value() << e->find("objectClass").value();
     }

     QLdapEntry a = searchResults->at(0);
     qDebug() << a.find("displayName").value() << a.find("title").value() << a.find("objectClass").value();

     QLdapUser *user = new QLdapUser(&a);

     qDebug() << user->getDisplayName();
     qDebug() << user->getCompany();

     qDebug() << user->toString();
     qDebug() << user;

     QLdapUser user1 = QLdapUser(&a);
     qDebug() << user1["company"];
     qDebug() << user1["displayName"];


     QLdapUser *user2 = new QLdapUser(&a);
     qDebug() << (*user2)["company"];
     qDebug() << (*user2)["displayName"];

     return;

}

MainWindow::~MainWindow()
{
    delete ui;
}

