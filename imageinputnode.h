// imageinputnode.h
#ifndef IMAGEINPUTNODE_H
#define IMAGEINPUTNODE_H

#include "BaseNode.h"
#include <QImage>

class GrayscaleNode;  // Forward declaration

class ImageInputNode : public BaseNode {
public:
    ImageInputNode();

    void loadImage(const QString& path);
    const QImage& getImage() const;

    void setNextNode(BaseNode* next); // NEW

private:
    QImage image;
    BaseNode* nextNode = nullptr;     // NEW
};

#endif // IMAGEINPUTNODE_H
