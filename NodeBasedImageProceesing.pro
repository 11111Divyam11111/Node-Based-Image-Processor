QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

SOURCES += \
    BaseNode.cpp \
    CanvasWidget.cpp \
    Connection.cpp \
    NodeCanvas.cpp \
    PropertiesPanelWidget.cpp \
    connectiondragmanager.cpp \
    grayscalenode.cpp \
    imageinputnode.cpp \
    imageviewernode.cpp \
    main.cpp \
    mainwindow.cpp \
    port.cpp \
    testnode.cpp

HEADERS += \
    BaseNode.h \
    CanvasWidget.h \
    Connection.h \
    NodeCanvas.h \
    NodeSocket.h \
    PortType.h \
    PropertiesPanelWidget.h \
    connectiondragmanager.h \
    grayscalenode.h \
    imageinputnode.h \
    imageviewernode.h \
    mainwindow.h \
    port.h \
    testnode.h

FORMS += \
    mainwindow.ui


INCLUDEPATH += D:/divya/Documents/opencv/build/include
DEPENDPATH += D:/divya/Documents/opencv/build/include

LIBS += -LD:/divya/Documents/opencv/build/x64/vc16/lib \
            -lopencv_world4110

# Deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
