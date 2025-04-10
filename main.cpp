
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("Node-Based Image Editor");
    window.resize(1280, 720);
    window.show();

    return app.exec();
}
