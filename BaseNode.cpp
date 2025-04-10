// BaseNode.cpp

#include "BaseNode.h"
#include <QPainter>

BaseNode::BaseNode(const QString& name)
    : nodeName(name)
{
    setFlags(ItemIsMovable | ItemIsSelectable);
}

QRectF BaseNode::boundingRect() const
{
    return QRectF(0, 0, 120, 60);
}

void BaseNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(isSelected() ? Qt::lightGray : Qt::white);
    painter->drawRect(boundingRect());

    painter->drawText(boundingRect(), Qt::AlignCenter, nodeName);
}
