#ifndef TableITEMDELEGATE_H
#define TableITEMDELEGATE_H

#include <QItemDelegate>
#include <QPolygonF>
#include <QPointF>

class TableItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    TableItemDelegate();

    QSize sizeHint(const QStyleOptionViewItem &option,
                       const QModelIndex &index) const override;

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
                  const QModelIndex &index) const override;
};

#endif // TableITEMDELEGATE_H
