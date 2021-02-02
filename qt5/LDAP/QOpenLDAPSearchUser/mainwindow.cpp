#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ldap.h"
#include "qldap.h"
#include "QDebug"
#include "qldapuser.h"
#include "qldapsearch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLdap *ldap = new QLdap();

     const QString url= "ldap://192.168.130.233:389";

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


    //Searсh begin
     QLdapEntryList *userSearchResult = new QLdapEntryList();

     QLdapSearch search = QLdapSearch(ldap);
     search.setDN("OU=Company,DC=altuninvv,DC=local");
     search.setResult(userSearchResult);

     result = search.user("");

     if ( result != LDAP_SUCCESS )
     {
         QString msg = QString("QLdapSearch error: ") + QString(ldap_err2string(result));
         qFatal("%s",msg.toLatin1().constData());
         ldap->close();
         return;
     }
     qDebug() << "User search result = " << ldap_err2string(result);

     QLdapEntry a = userSearchResult->at(0);
     QLdapUser user1 = QLdapUser(&a);
     qDebug() << user1["company"];
     qDebug() << user1["displayName"];

     qDebug() << "============";


     //Search by name
      result = search.user("(displayName=орло*)");

      if ( result != LDAP_SUCCESS )
      {
          QString msg = QString("QLdapSearch error: ") + QString(ldap_err2string(result));
          qFatal("%s",msg.toLatin1().constData());
          ldap->close();
          return;
      }
      qDebug() << "User search result = " << ldap_err2string(result);


      a = userSearchResult->at(0);
      user1 = QLdapUser(&a);
      qDebug() << user1["company"];
      qDebug() << user1["displayName"];

      qDebug() << "============";


      //Search by name method
       result = search.userByName("федор*");

       if ( result != LDAP_SUCCESS )
       {
           QString msg = QString("QLdapSearch error: ") + QString(ldap_err2string(result));
           qFatal("%s",msg.toLatin1().constData());
           ldap->close();
           return;
       }
       qDebug() << "User name search result = " << ldap_err2string(result);


       for( auto e = userSearchResult->begin(); e != userSearchResult->end(); ++e)
       {
           user1 = QLdapUser(&(*e));
           qDebug() << user1["company"];
           qDebug() << user1["displayName"];

       }

       qDebug() << "============";


       //Search by login method
        result = search.userByLogin("ber*");

        if ( result != LDAP_SUCCESS )
        {
            QString msg = QString("QLdapSearch error: ") + QString(ldap_err2string(result));
            qFatal("%s",msg.toLatin1().constData());
            ldap->close();
            return;
        }
        qDebug() << "User name search result = " << ldap_err2string(result);


        for( auto e = userSearchResult->begin(); e != userSearchResult->end(); ++e)
        {
            user1 = QLdapUser(&(*e));
            qDebug() << user1["company"];
            qDebug() << user1["displayName"];

        }

        qDebug() << "============";





     //Close
     result = ldap->close();
     if ( result != LDAP_SUCCESS )
     {
         QString msg = QString("QLDAP init() error: ") + QString(ldap_err2string(result));
         qFatal("%s",msg.toLatin1().constData());
         return;
     }
     qDebug() << "Close result = " << ldap_err2string(result);


     return;

}

MainWindow::~MainWindow()
{
    delete ui;
}

