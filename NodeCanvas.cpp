// NodeCanvas.cpp

#include "nodecanvas.h"

NodeCanvas::NodeCanvas(QObject *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);  // Optional: define canvas size
}

QGraphicsScene *NodeCanvas::getScene()
{
    return scene;
}
