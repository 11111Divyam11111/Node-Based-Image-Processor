// PropertiesPanelWidget.cpp
#include "PropertiesPanelWidget.h"

PropertiesPanelWidget::PropertiesPanelWidget(QWidget *parent)
    : QWidget(parent) {
    layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Properties Panel");
    layout->addWidget(label);
    layout->addStretch();
    setStyleSheet("background-color: #2d2d2d; color: white;");
    setMinimumWidth(250);
}
