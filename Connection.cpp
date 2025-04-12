#include "Connection.h"
#include <QPainterPath>
#include <QPen>

Connection::Connection(Port* from, Port* to)
    : fromSocket(from), toSocket(to)
{
    setZValue(0); // Render below other items
    setPen(QPen(Qt::blue, 2));
    updatePath();
}

void Connection::updatePath() {
    if (!fromSocket) return;

    QPointF p1 = fromSocket->scenePos();
    QPointF p2 = toSocket ? toSocket->scenePos() : p1;

    updatePath(p1, p2);
}

void Connection::updatePath(const QPointF& fromPos, const QPointF& toPos) {
    QPainterPath path(fromPos);
    QPointF ctrl1 = fromPos + QPointF(50, 0);
    QPointF ctrl2 = toPos - QPointF(50, 0);
    path.cubicTo(ctrl1, ctrl2, toPos);
    setPath(path);
}
