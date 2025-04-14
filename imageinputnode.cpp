// imageinputnode.cpp
#include "imageinputnode.h"
#include "grayscalenode.h"
#include <QDebug>

ImageInputNode::ImageInputNode()
    : BaseNode("Image Input") {
    addOutputPort("Image");
}

void ImageInputNode::loadImage(const QString& path) {
    image.load(path);
    if (!image.isNull()) {
        qDebug() << "Image loaded successfully";

        if (nextNode) {
            auto grayscale = dynamic_cast<GrayscaleNode*>(nextNode);
            if (grayscale) {
                grayscale->setInputImage(image);
            }
        }
    } else {
        qDebug() << "Failed to load image!";
    }
}

const QImage& ImageInputNode::getImage() const {
    return image;
}

void ImageInputNode::setNextNode(BaseNode* next) {
    nextNode = next;
}
