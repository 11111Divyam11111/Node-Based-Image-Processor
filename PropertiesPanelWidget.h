#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

class PropertiesPanelWidget : public QWidget {
    Q_OBJECT

public:
    explicit PropertiesPanelWidget(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
};
