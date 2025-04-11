// Port.h
#ifndef PORT_H
#define PORT_H

#include <QGraphicsItem>
#include <QString>
#include <QGraphicsTextItem>

enum class PortType { Input, Output };

class Port : public QGraphicsItem {
public:
    Port(PortType type, QGraphicsItem* parent = nullptr);

    void setLabel(const QString& text);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;

private:
    PortType portType;
    QString label;
    QGraphicsTextItem* labelItem;
};

#endif // PORT_H
