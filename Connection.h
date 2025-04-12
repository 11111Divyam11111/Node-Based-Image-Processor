// Connection.h
#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsPathItem>
#include "port.h"

class Connection : public QGraphicsPathItem {
public:
    Connection(Port* from, Port* to = nullptr);

    void updatePath();
    void updatePath(const QPointF& fromPos, const QPointF& toPos); // Overload for dragging

    Port* fromSocket;
    Port* toSocket;
};

#endif // CONNECTION_H
