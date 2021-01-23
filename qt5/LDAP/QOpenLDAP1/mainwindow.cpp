#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ldap.h"
#include "qldap.h"
#include "QDebug"

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

