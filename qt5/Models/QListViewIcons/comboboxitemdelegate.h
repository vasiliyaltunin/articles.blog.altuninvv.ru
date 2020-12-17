#ifndef COMBOBOXITEMDELEGATE_H
#define COMBOBOXITEMDELEGATE_H

#include <QItemDelegate>
#include <QPolygonF>
#include <QPointF>

class ComboboxItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    ComboboxItemDelegate();

    QSize sizeHint(const QStyleOptionViewItem &option,
                       const QModelIndex &index) const override;

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
                  const QModelIndex &index) const override;
};

#endif // COMBOBOXITEMDELEGATE_H
