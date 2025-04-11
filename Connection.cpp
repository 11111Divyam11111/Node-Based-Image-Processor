// Connection.cpp
#include "Connection.h"
#include <QPainterPath>
#include <QPen>

Connection::Connection(NodeSocket* from, NodeSocket* to)
    : fromSocket(from), toSocket(to) {
    setZValue(-1); // Make sure connections render below nodes
    setPen(QPen(Qt::black, 2));
    updatePath();
}

void Connection::updatePath() {
    if (!fromSocket || !toSocket) return;

    QPointF start = fromSocket->scenePos();
    QPointF end = toSocket->scenePos();

    QPainterPath path(start);
    qreal dx = (end.x() - start.x()) * 0.5;
    path.cubicTo(start.x() + dx, start.y(), end.x() - dx, end.y(), end.x(), end.y());

    setPath(path);
}
