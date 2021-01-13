#include "qlampwidgetmodel.h"

#include <QPointer>

QLampWidgetModel::QLampWidgetModel()
{

}

int QLampWidgetModel::rowCount(const QModelIndex &) const
{
    return 1;
}

QVariant QLampWidgetModel::data(const QModelIndex &index, int role) const
{
    QVariant value;

        switch ( role )
        {
            case Qt::DisplayRole: //string
            {
                value = this->status->toInt();
            }
            break;

            default:
                break;
        }

        return value;
}

void QLampWidgetModel::populate(QString *status)
{
    this->status = status;
    emit statusUpdated();
}
