// grayscalenode.cpp
#include "grayscalenode.h"
#include <QDebug>
#include "imageviewernode.h"
GrayscaleNode::GrayscaleNode()
    : BaseNode("Grayscale") {
    addInputPort("Image");
    addOutputPort("Grayscale Image");
}

void GrayscaleNode::setInputImage(const QImage& image) {
    inputImage = image;
    process();
}

void GrayscaleNode::process() {
    if (inputImage.isNull()) return;

    outputImage = inputImage.convertToFormat(QImage::Format_Grayscale8);
    qDebug() << "Grayscale conversion done using Qt.";

    if (nextNode) {
        auto viewer = dynamic_cast<ImageViewerNode*>(nextNode);
        if (viewer) {
            viewer->setImage(outputImage);
        }
    }
}

void GrayscaleNode::setNextNode(BaseNode* next) {
    nextNode = next;
}
const QImage& GrayscaleNode::getOutputImage() const {
    return outputImage;
}
