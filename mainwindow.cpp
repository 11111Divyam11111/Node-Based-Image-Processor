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

    TestNode *testNode = new TestNode();
    testNode->setPos(100, 100);
    nodeCanvas->getScene()->addItem(testNode);
}

MainWindow::~MainWindow()
{
    delete ui;
}
