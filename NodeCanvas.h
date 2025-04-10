// NodeCanvas.h

#ifndef NODECANVAS_H
#define NODECANVAS_H

#include <QGraphicsScene>

class NodeCanvas
{
public:
    NodeCanvas(QObject *parent = nullptr);

    QGraphicsScene *getScene();

private:
    QGraphicsScene *scene;
};

#endif // NODECANVAS_H
