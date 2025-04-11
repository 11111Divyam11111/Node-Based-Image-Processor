// BaseNode.h
#ifndef BASENODE_H
#define BASENODE_H

#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QVector>
#include "port.h"

class BaseNode : public QGraphicsItem
{
public:
    BaseNode(const QString &name);
    virtual ~BaseNode() = default;

    void addInputPort(const QString &label);
    void addOutputPort(const QString &label);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    virtual void process() = 0; // Must be implemented by derived classes

protected:
    QRectF nodeRect;
    QGraphicsTextItem *titleText;

    QVector<Port*> inputPorts;
    QVector<Port*> outputPorts;

    void layoutPorts();  // Arrange ports on sides
};

#endif // BASENODE_H
