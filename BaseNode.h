// BaseNode.h

#ifndef BASENODE_H
#define BASENODE_H

#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QVector>
#include <QString>

#include "port.h"

class BaseNode : public QGraphicsItem
{
public:
    // Constructor
    BaseNode(const QString& name);

    // Virtual destructor
    virtual ~BaseNode() = default;

    // Virtual processing function to override in child nodes
    virtual void process() {}

    // Add ports
    void addInputPort(const QString& label);
    void addOutputPort(const QString& label);

    // Qt painting functions
    virtual QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

protected:
    // Layout helper
    void layoutPorts();

    // Data
    QString nodeName;
    QRectF nodeRect;
    QGraphicsTextItem* titleText;

    QVector<Port*> inputPorts;
    QVector<Port*> outputPorts;
};

#endif // BASENODE_H
