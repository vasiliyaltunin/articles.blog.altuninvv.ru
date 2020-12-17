#ifndef QLISTVIEWMODEL_H
#define QLISTVIEWMODEL_H


#include "countryflag.h"

#include <QModelIndex>

class QListViewModel : public QAbstractListModel
{
public:
    QListViewModel(QObject *parent=nullptr);
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    void populate(QList<CountryFlag> *newValues);
    void append(CountryFlag value);
    void update(int idx, CountryFlag value);
    void deleteRow(int idx);
    void insertAt(int idx, CountryFlag value);
private:
    QList<CountryFlag> *values;
};

#endif // QLISTVIEWMODEL_H
