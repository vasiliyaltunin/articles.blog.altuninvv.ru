#ifndef QLAMPWIDGETMODEL_H
#define QLAMPWIDGETMODEL_H

#include <QAbstractListModel>
#include <QPointer>
#include <QObject>



class QLampWidgetModel : public QAbstractListModel
{

    Q_OBJECT

public:
    QLampWidgetModel();
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;

    void populate(QString *status);

private:
    QString *status;

signals:
    void statusUpdated();

};

#endif // QLAMPWIDGETMODEL_H
