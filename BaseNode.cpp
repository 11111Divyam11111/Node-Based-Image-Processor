// BaseNode.cpp

#include "BaseNode.h"
#include "port.h"
#include <QPainter>

BaseNode::BaseNode(const QString &name)
    : nodeName(name)
{
    nodeRect = QRectF(0, 0, 150, 80);

    titleText = new QGraphicsTextItem(name, this);
    titleText->setPos(10, 0);

    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setAcceptHoverEvents(true);
}

void BaseNode::addInputPort(const QString& /*label*/)
{
    Port* port = new Port(PortType::Input, this);
    port->setParentItem(this);
    inputPorts.append(port);
    layoutPorts();
}

void BaseNode::addOutputPort(const QString& /*label*/)
{
    Port* port = new Port(PortType::Output, this);
    port->setParentItem(this);
    outputPorts.append(port);
    layoutPorts();
}

// ✅ Define layoutPorts() to avoid undefined reference error
void BaseNode::layoutPorts()
{
    const int spacing = 20;

    for (int i = 0; i < inputPorts.size(); ++i)
        inputPorts[i]->setPos(0, 25 + i * spacing);

    for (int i = 0; i < outputPorts.size(); ++i)
        outputPorts[i]->setPos(nodeRect.width() - 12, 25 + i * spacing);
}

QRectF BaseNode::boundingRect() const {
    // Increase default node size here (e.g. 300x180)
    return QRectF(0, 0, 600, 400);
}

void BaseNode::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(Qt::lightGray);
    painter->drawRoundedRect(nodeRect, 10, 10);
}
