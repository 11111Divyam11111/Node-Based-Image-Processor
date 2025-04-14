// NodeCanvas.cpp

#include "NodeCanvas.h"

NodeCanvas::NodeCanvas(QObject *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1000, 800);  // Optional: define canvas size
}

QGraphicsScene *NodeCanvas::getScene()
{
    return scene;
}
