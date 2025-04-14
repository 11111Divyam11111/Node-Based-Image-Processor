// grayscalenode.h
#ifndef GRAYSCALENODE_H
#define GRAYSCALENODE_H

#include "BaseNode.h"
#include <QImage>

class GrayscaleNode : public BaseNode {
public:
    GrayscaleNode();

    void setInputImage(const QImage& image);
    void process() override;
    void setNextNode(BaseNode* next); // NEW
    const QImage& getOutputImage() const;
    BaseNode* nextNode = nullptr;
private:
    QImage inputImage;
    QImage outputImage;
};

#endif // GRAYSCALENODE_H
