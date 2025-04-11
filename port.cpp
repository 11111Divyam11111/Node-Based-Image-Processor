// Port.cpp
#include "port.h"
#include <QPainter>

Port::Port(PortType type, QGraphicsItem* parent)
    : QGraphicsItem(parent), portType(type) {
    labelItem = new QGraphicsTextItem(this);
    labelItem->setPos(15, -5); // offset label slightly
}

void Port::setLabel(const QString& text) {
    label = text;
    labelItem->setPlainText(text);
}

QRectF Port::boundingRect() const {
    return QRectF(0, 0, 10, 10); // Small circle for port
}

void Port::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}
