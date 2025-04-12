// Port.h
#ifndef PORT_H
#define PORT_H

#include <QGraphicsEllipseItem>
#include "PortType.h"

class Port : public QGraphicsEllipseItem {
public:
    Port(PortType type, QGraphicsItem* parent = nullptr);

    void setLabel(const QString& label);
    PortType getPortType() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

private:
    PortType m_type;
    QGraphicsTextItem* m_label;
    bool m_dragStarted;
};

#endif // PORT_H
