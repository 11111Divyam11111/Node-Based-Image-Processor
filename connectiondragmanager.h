// ConnectionDragManager.h
#ifndef CONNECTIONDRAGMANAGER_H
#define CONNECTIONDRAGMANAGER_H

#include "Connection.h"
#include "port.h" // ✅ update to use Port*

class ConnectionDragManager {
public:
    static ConnectionDragManager* instance();

    void beginDrag(Port* fromPort);      // ✅ updated
    void updateDrag(const QPointF& pos);
    void endDrag(Port* toPort);          // ✅ updated
    void cancelDrag();

private:
    ConnectionDragManager() = default;
    Connection* tempConnection = nullptr;
    Port* startPort = nullptr;
};

#endif // CONNECTIONDRAGMANAGER_H
