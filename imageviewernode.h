// imageviewernode.h
#ifndef IMAGEVIEWERNODE_H
#define IMAGEVIEWERNODE_H

#include "BaseNode.h"
#include <QImage>

class ImageViewerNode : public BaseNode {
public:
    ImageViewerNode();

    void setImage(const QImage& image);
    void process() override;

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    QRectF boundingRect() const override;

private:
    QImage image;
};

#endif // IMAGEVIEWERNODE_H
