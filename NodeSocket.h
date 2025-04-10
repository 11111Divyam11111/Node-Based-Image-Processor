// NodeSocket.h
#ifndef NODESOCKET_H
#define NODESOCKET_H

#include <QGraphicsItem>
#include <QVariant>

class NodeSocket : public QGraphicsItem {
public:
    enum SocketType { Input, Output };

    NodeSocket(SocketType type);
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

    SocketType socketType;
    QVariant data;
};

#endif // NODESOCKET_H
