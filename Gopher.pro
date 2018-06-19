#-------------------------------------------------
#
# Project created by QtCreator 2018-05-25T15:28:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gopher
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
        main.cpp \
        mainwindow.cpp \
    centralwidget.cpp \
    Widgets/expandablewidget.cpp \
    Mesh/mesh.cpp \
    Mesh/vertex.cpp \
    Mesh/face.cpp \
    Mesh/halfedge.cpp \
    Widgets/meshwidget.cpp \
    Widgets/vertexwidget.cpp \
    Widgets/halfedgewidget.cpp \
    Widgets/facewidget.cpp \
    Widgets/widgettools.cpp \
    Widgets/delayedexpandablewidget.cpp \
    Widgets/delayedinspectionwidget.cpp \
    Widgets/gridwidget.cpp \
    Widgets/treewidget.cpp

HEADERS += \
        mainwindow.h \
    centralwidget.h \
    Widgets/expandablewidget.h \
    Mesh/mesh.h \
    Mesh/vertex.h \
    Mesh/face.h \
    Widgets/vectorwidget.h \
    Mesh/halfedge.h \
    Widgets/meshwidget.h \
    layoutfactory.h \
    Widgets/vertexwidget.h \
    Widgets/halfedgewidget.h \
    Widgets/facewidget.h \
    Widgets/widgettools.h \
    Widgets/inspectionwidget.h \
    Widgets/delayedinspectionwidget.h \
    Widgets/gridwidget.h \
    Widgets/treewidget.h

CONFIG += c++14
