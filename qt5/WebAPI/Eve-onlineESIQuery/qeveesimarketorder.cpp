#include "qeveesimarketorder.h"

QEveESIMarketOrder::QEveESIMarketOrder()
{

}

QEveESIMarketOrder::QEveESIMarketOrder(QJsonObject data)
{
    this->duration = data["duration"].toInt();
    this->is_buy_order = data["is_buy_order"].toString();
    this->issued = data["issued"].toString();
    this->location_id = data["location_id"].toInt();
    this->min_volume = data["min_volume"].toInt();
    this->order_id = data["order_id"].toInt();
    this->price = data["price"].toDouble();
    this->range = data["range"].toString();
    this->system_id = data["system_id"].toInt();
    this->type_id = data["type_id"].toInt();
    this->volume_remain = data["volume_remain"].toInt();
    this->volume_total = data["volume_total"].toInt();
}


int QEveESIMarketOrder::getDuration() const
{
    return duration;
}

void QEveESIMarketOrder::setDuration(int value)
{
    duration = value;
}

QString QEveESIMarketOrder::getIs_buy_order() const
{
    return is_buy_order;
}

void QEveESIMarketOrder::setIs_buy_order(const QString &value)
{
    is_buy_order = value;
}

QString QEveESIMarketOrder::getIssued() const
{
    return issued;
}

void QEveESIMarketOrder::setIssued(const QString &value)
{
    issued = value;
}

int QEveESIMarketOrder::getLocation_id() const
{
    return location_id;
}

void QEveESIMarketOrder::setLocation_id(int value)
{
    location_id = value;
}

int QEveESIMarketOrder::getMin_volume() const
{
    return min_volume;
}

void QEveESIMarketOrder::setMin_volume(int value)
{
    min_volume = value;
}

int QEveESIMarketOrder::getOrder_id() const
{
    return order_id;
}

void QEveESIMarketOrder::setOrder_id(int value)
{
    order_id = value;
}

float QEveESIMarketOrder::getPrice() const
{
    return price;
}

void QEveESIMarketOrder::setPrice(float value)
{
    price = value;
}

QString QEveESIMarketOrder::getRange() const
{
    return range;
}

void QEveESIMarketOrder::setRange(const QString &value)
{
    range = value;
}

int QEveESIMarketOrder::getSystem_id() const
{
    return system_id;
}

void QEveESIMarketOrder::setSystem_id(int value)
{
    system_id = value;
}

int QEveESIMarketOrder::getType_id() const
{
    return type_id;
}

void QEveESIMarketOrder::setType_id(int value)
{
    type_id = value;
}

int QEveESIMarketOrder::getVolume_remain() const
{
    return volume_remain;
}

void QEveESIMarketOrder::setVolume_remain(int value)
{
    volume_remain = value;
}

int QEveESIMarketOrder::getVolume_total() const
{
    return volume_total;
}

void QEveESIMarketOrder::setVolume_total(int value)
{
    volume_total = value;
}

QDebug operator<<(QDebug debug, const QEveESIMarketOrder &order)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << "QEveESIMarketOrder ("
                    << " duration: " << order.getDuration() << ","
                    << " is_buy_order: " << order.getIs_buy_order() << ","
                    << " issued: " << order.getIssued() << ","
                    << " location_id: " << order.getLocation_id() << ","
                    << " min_volume: " << order.getMin_volume() << ","
                    << " order_id: " << order.getOrder_id() << ","
                    << " price: " << order.getPrice() << ","
                    << " range: " << order.getRange() << ","
                    << " system_id: " << order.getSystem_id() << ","
                    << " type_id: " << order.getType_id() << ","
                    << " volume_remain: " << order.getVolume_remain() << ","
                    << " volume_total: " << order.getVolume_total()
                    << ")";
    return debug;
}

QDebug operator<<(QDebug debug, const QEveESIMarketOrder *order)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << *order;
    return debug;
}
