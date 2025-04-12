// Port.cpp
#include "port.h"
#include "ConnectionDragManager.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
Port::Port(PortType type, QGraphicsItem* parent)
    : QGraphicsEllipseItem(parent), m_type(type), m_label(nullptr), m_dragStarted(false)
{
    // Set a visible circle shape
    setRect(-6, -6, 12, 12);                     // Small circle centered at (0,0)
    setBrush(Qt::yellow);                         // Make it visible
    setPen(QPen(Qt::yellow));

    // Enable mouse interaction
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::LeftButton);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
}

void Port::setLabel(const QString& label) {
    if (!m_label) {
        m_label = new QGraphicsTextItem(label, this);
        if (m_type == PortType::Input)
            m_label->setPos(-50, -5);
        else
            m_label->setPos(20, -5);
    } else {
        m_label->setPlainText(label);
    }
}

PortType Port::getPortType() const {
    return m_type;
}



void Port::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    if (m_dragStarted) {
        ConnectionDragManager::instance()->updateDrag(event->scenePos());
    }
    QGraphicsEllipseItem::mouseMoveEvent(event);
}


void Port::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    qDebug() << "Port::mousePressEvent - Started drag on" << this;
    m_dragStarted = true;
    ConnectionDragManager::instance()->beginDrag(this);
    QGraphicsEllipseItem::mousePressEvent(event);
}

void Port::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    qDebug() << "Port::mouseReleaseEvent - Released on" << this;

    if (m_dragStarted) {
        QList<QGraphicsItem*> items = scene()->items(event->scenePos());

        for (QGraphicsItem* item : items) {
            Port* port = dynamic_cast<Port*>(item);
            if (port && port != this &&
                port->getPortType() == PortType::Input) {

                qDebug() << "Found valid target port:" << port;
                ConnectionDragManager::instance()->endDrag(port);
                m_dragStarted = false;
                return;
            }
        }

        qDebug() << "No valid port under mouse. Cancelling drag.";
        ConnectionDragManager::instance()->cancelDrag();
        m_dragStarted = false;
    }

    QGraphicsEllipseItem::mouseReleaseEvent(event);
}
