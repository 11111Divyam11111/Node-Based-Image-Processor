// mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imageinputnode.h"
#include "NodeCanvas.h"
#include "TestNode.h"
#include "imageinputnode.h"
#include "grayscalenode.h"
#include "imageviewernode.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    nodeCanvas = new NodeCanvas(this);
    ui->graphicsViewCanvas->setScene(nodeCanvas->getScene());

    ImageInputNode* inputNode = new ImageInputNode();
    GrayscaleNode* grayNode = new GrayscaleNode();
    ImageViewerNode* viewNode = new ImageViewerNode();

    nodeCanvas->getScene()->addItem(inputNode);
    nodeCanvas->getScene()->addItem(grayNode);
    nodeCanvas->getScene()->addItem(viewNode);

    inputNode->setPos(200, 100);
    grayNode->setPos(400, 100);
    viewNode->setPos(600, 100);

    inputNode->setNextNode(grayNode);
    grayNode->setNextNode(viewNode);

    // Load image to trigger the pipeline
    inputNode->loadImage("D:/Idk/Me.jpg");

    ImageViewerNode* viewerNode = new ImageViewerNode();
    viewerNode->setImage(QImage("D:/Idk/Me.jpg")); // TEMP for testing
    nodeCanvas->getScene()->addItem(viewerNode);
    viewerNode->setPos(0, 100);

    ui->graphicsViewCanvas->setScene(nodeCanvas->getScene());

    // Disable scrollbars
    ui->graphicsViewCanvas->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsViewCanvas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->graphicsViewCanvas->centerOn(0, 0);

}

MainWindow::~MainWindow()
{
    delete ui;
}
