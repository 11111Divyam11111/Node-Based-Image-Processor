// imageviewernode.cpp
#include "imageviewernode.h"
#include <QPainter>

ImageViewerNode::ImageViewerNode()
    : BaseNode("Image Viewer") {
    addInputPort("Image");
}

void ImageViewerNode::setImage(const QImage& img) {
    image = img;
    update(); // Trigger repaint
}

void ImageViewerNode::process() {
    // You can trigger image processing or refresh from connections if needed
}

void ImageViewerNode::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    BaseNode::paint(painter, option, widget);

    if (!image.isNull()) {
        QRectF imageRect(10, 30, boundingRect().width() - 20, boundingRect().height() - 40);
        QImage scaled = image.scaled(imageRect.size().toSize(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        QPoint drawPoint(imageRect.left(), imageRect.top());
        painter->drawImage(drawPoint, scaled);
    }
}

QRectF ImageViewerNode::boundingRect() const {
    return QRectF(0, 0, 320, 240);  // Bigger node area
}
