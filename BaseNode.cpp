// BaseNode.cpp
#include "BaseNode.h"
#include "port.h"
#include <QPainter>

BaseNode::BaseNode(const QString &name)
{
    nodeRect = QRectF(0, 0, 150, 80);

    titleText = new QGraphicsTextItem(name, this);
    titleText->setPos(10, 0);

    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setAcceptHoverEvents(true);
}


void BaseNode::addInputPort(const QString &label)
{
    Port *port = new Port(PortType::Input, this);
    port->setLabel(label);
    inputPorts.append(port);
    layoutPorts();
}

void BaseNode::addOutputPort(const QString &label)
{
    Port *port = new Port(PortType::Output, this);
    port->setLabel(label);
    outputPorts.append(port);
    layoutPorts();
}

void BaseNode::layoutPorts()
{
    // Layout input ports on the left
    const int spacing = 20;
    for (int i = 0; i < inputPorts.size(); ++i) {
        inputPorts[i]->setPos(0, 25 + i * spacing);
    }

    // Layout output ports on the right
    for (int i = 0; i < outputPorts.size(); ++i) {
        outputPorts[i]->setPos(nodeRect.width() - 12, 25 + i * spacing);
    }
}

QRectF BaseNode::boundingRect() const
{
    return nodeRect.adjusted(-2, -2, 2, 2);
}

void BaseNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(Qt::lightGray);
    painter->drawRoundedRect(nodeRect, 10, 10);
}
