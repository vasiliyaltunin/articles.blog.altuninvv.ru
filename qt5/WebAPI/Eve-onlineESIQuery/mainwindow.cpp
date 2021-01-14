/****************************************************************************
**
** Copyright 2021 Vasiliy Altunin <skyr@altuninvv.ru>. All rights reserved.
**
** Use of this source code is governed by a BSD-style
** license that can be found in the LICENSE file.
**
** Created for articles of site https://blog.altuninvv.ru
**
** WebAPI request demo from EVE Online ESI
**
****************************************************************************/

#include "mainwindow.h"
#include "qeveesimarketorder.h"
#include "ui_mainwindow.h"

#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QNetworkAccessManager *netMan = new QNetworkAccessManager(this);
    QUrl url("https://esi.evetech.net/dev/markets/10000002/orders/?datasource=tranquility&order_type=sell&type_id=34");

    QObject::connect(netMan, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));

    QNetworkReply* reply = netMan->get(QNetworkRequest(url));

    //delete reply;

}

void MainWindow::onResult(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError) {

            QStringList propertyNames;
            QStringList propertyKeys;

            QString strReply = (QString)reply->readAll();


            QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

            QJsonArray jsonArray = jsonResponse.array();


            QList<QEveESIMarketOrder*> *ordersist = new  QList<QEveESIMarketOrder*>();

            foreach (QJsonValue jsonObject, jsonArray) {
                QEveESIMarketOrder *order = new QEveESIMarketOrder(jsonObject.toObject());
                ordersist->append(order);
            }

            qDebug() << ordersist->toVector();

//            qDebug() << order;

        } else {
            qDebug() << "ERROR";
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

