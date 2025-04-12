// ConnectionDragManager.cpp
#include "connectiondragmanager.h"
#include <QGraphicsScene>

ConnectionDragManager* ConnectionDragManager::instance() {
    static ConnectionDragManager inst;
    return &inst;
}


void ConnectionDragManager::updateDrag(const QPointF& pos) {
    if (tempConnection) {
        tempConnection->updatePath(startPort->scenePos(), pos); // ✅ Proper drag line
    }
}
void ConnectionDragManager::beginDrag(Port* fromPort) {
    qDebug() << "Begin drag from port:" << fromPort;
    startPort = fromPort;
    tempConnection = new Connection(fromPort, nullptr);
    fromPort->scene()->addItem(tempConnection);
}

void ConnectionDragManager::endDrag(Port* toPort) {
    qDebug() << "End drag to port:" << toPort;

    if (tempConnection && startPort && toPort &&
        startPort->getPortType() == PortType::Output &&
        toPort->getPortType() == PortType::Input) {

        tempConnection->toSocket = toPort;
        tempConnection->updatePath();
        tempConnection = nullptr;
        startPort = nullptr;
    } else {
        qDebug() << "Invalid connection, cancelling.";
        cancelDrag();
    }
}

void ConnectionDragManager::cancelDrag() {
    if (tempConnection) {
        if (tempConnection->scene()) {
            tempConnection->scene()->removeItem(tempConnection);
        }
        delete tempConnection;
        tempConnection = nullptr;
    }
    startPort = nullptr;
}
