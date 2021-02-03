#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ldap.h"
#include "qldap.h"
#include "QDebug"
#include "qldapuser.h"
#include "qldapsearch.h"
#include "qldapgroup.h"

void checkForSearchLDAPErrors(QLdap *ldap, int result)
{
    if ( result != LDAP_SUCCESS )
    {
    QString msg = QString("QLdapSearch error: ") + QString(ldap_err2string(result));
    ldap->close();
    qFatal("%s",msg.toLatin1().constData());
    }
    qDebug() << "LDAP Search result = " << ldap_err2string(result);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLdap *ldap = new QLdap();

    const QString url= "ldap://192.168.1.1:389";

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

    qDebug() << "\n========\n";
    //Search start

    QLdapEntry a;

    QLdapSearch search = QLdapSearch(ldap);

    QLdapEntryList *groupSearchResult = new QLdapEntryList();

    search.setDN("OU=Company,DC=altuninvv,DC=local");
    search.setResult(groupSearchResult);

    //Find all groups
    result = search.group("");
    checkForSearchLDAPErrors(ldap, result);

    a = groupSearchResult->at(0);
    qDebug() << "\n========\n" << a << "\n=========";

    //Find all group members
    result = search.group("");
    checkForSearchLDAPErrors(ldap, result);

    a = groupSearchResult->at(0);
    QLdapGroup g = QLdapGroup(&a);
    qDebug() << "\n========\n" << g.getMembers() << "\n=========";


    //Find members of gg-it
    result = search.group("(name=gg-it)");
    checkForSearchLDAPErrors(ldap, result);

    a = groupSearchResult->at(0);
    g = QLdapGroup(&a);
    qDebug() << "\n========\n" << g.getMembers() << "\n=========";


    //Find group DN
    result = search.group("(name=gg-it)");
    checkForSearchLDAPErrors(ldap, result);

    a = groupSearchResult->at(0);
    g = QLdapGroup(&a);
    qDebug() << "\n========\n" << g.getDN() << "\n=========";


    //Find all users of group gg-buh
    result = search.group("(name=gg-buh)");
    checkForSearchLDAPErrors(ldap, result);

    a = groupSearchResult->at(0);
    g = QLdapGroup(&a);
    qDebug() << "\n========\n" << g.getDN() << "\n=========";

    QString aDN =  g.getDN();

    result = search.usersInGroup(aDN);
    checkForSearchLDAPErrors(ldap, result);

    for( auto e = groupSearchResult->begin(); e != groupSearchResult->end(); ++e)
    {
        QLdapUser user2 = QLdapUser(&(*e));
        qDebug() << user2["company"];
        qDebug() << user2["displayName"];
    }
    qDebug() << "\n========\n";


    //Search end
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

