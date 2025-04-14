
#include <QApplication>
#include "mainwindow.h"

#include <iostream>
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("Node-Based Image Editor");
    window.resize(1000, 800);
    window.show();

    return app.exec();
}
