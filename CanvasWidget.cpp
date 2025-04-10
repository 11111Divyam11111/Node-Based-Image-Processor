// CanvasWidget.cpp
#include "CanvasWidget.h"

CanvasWidget::CanvasWidget(QWidget *parent)
    : QWidget(parent) {
    setMinimumSize(800, 600);
    setStyleSheet("background-color: #1e1e1e;");
}

//
void CanvasWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::gray);
    painter.drawText(rect().center(), "Canvas Area");
}
