// mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "nodecanvas.h"
#include "TestNode.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    nodeCanvas = new NodeCanvas(this);
    ui->graphicsViewCanvas->setScene(nodeCanvas->getScene());

    BaseNode* node1 = new TestNode();
    node1->addOutputPort("Out");
    nodeCanvas->getScene()->addItem(node1);
    node1->setPos(50, 100);

    BaseNode* node2 = new TestNode();
    node2->addInputPort("In");
    nodeCanvas->getScene()->addItem(node2);
    node2->setPos(300, 100); // place to the right of node1

}

MainWindow::~MainWindow()
{
    delete ui;
}
