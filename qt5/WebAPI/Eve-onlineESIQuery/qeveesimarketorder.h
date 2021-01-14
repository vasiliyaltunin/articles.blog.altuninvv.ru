#ifndef QEVEESIMARKETORDER_H
#define QEVEESIMARKETORDER_H

#include <QDebug>
#include <QJsonObject>
#include <QString>



class QEveESIMarketOrder
{
public:
    QEveESIMarketOrder();
    QEveESIMarketOrder(QJsonObject data);

    int getDuration() const;
    void setDuration(int value);

    QString getIs_buy_order() const;
    void setIs_buy_order(const QString &value);

    QString getIssued() const;
    void setIssued(const QString &value);

    int getLocation_id() const;
    void setLocation_id(int value);

    int getMin_volume() const;
    void setMin_volume(int value);

    int getOrder_id() const;
    void setOrder_id(int value);

    float getPrice() const;
    void setPrice(float value);

    QString getRange() const;
    void setRange(const QString &value);

    int getSystem_id() const;
    void setSystem_id(int value);

    int getType_id() const;
    void setType_id(int value);

    int getVolume_remain() const;
    void setVolume_remain(int value);

    int getVolume_total() const;
    void setVolume_total(int value);

private:

    int duration;
    QString is_buy_order;
    QString issued;
    int location_id;
    int min_volume;
    int order_id;
    float price;
    QString range;
    int system_id;
    int type_id;
    int volume_remain;
    int volume_total;
};

QDebug operator<<(QDebug debug, const QEveESIMarketOrder &order);
QDebug operator<<(QDebug debug, const QEveESIMarketOrder *order);


#endif // QEVEESIMARKETORDER_H
