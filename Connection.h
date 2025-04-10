// Connection.h
#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsPathItem>
#include "NodeSocket.h"

class Connection : public QGraphicsPathItem {
public:
    Connection(NodeSocket* from, NodeSocket* to);
    void updatePath();

    NodeSocket* fromSocket;
    NodeSocket* toSocket;
};

#endif // CONNECTION_H
