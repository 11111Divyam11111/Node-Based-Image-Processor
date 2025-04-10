// BaseNode.h

#ifndef BASENODE_H
#define BASENODE_H

#include <QGraphicsItem>
#include <QString>

class BaseNode : public QGraphicsItem
{
public:
    BaseNode(const QString& name);

    virtual void process() = 0; // Must be implemented in derived class

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

protected:
    QString nodeName;
};

#endif // BASENODE_H
