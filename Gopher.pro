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
    expandablewidget.cpp \
    expandabletreewidget.cpp \
    Mesh/mesh.cpp \
    Mesh/vertex.cpp \
    Mesh/face.cpp \
    Mesh/halfedge.cpp \
    Mesh/meshwidget.cpp \
    Mesh/vertexwidget.cpp \
    Mesh/halfedgewidget.cpp \
    Mesh/facewidget.cpp \
    Mesh/widgettools.cpp \
    delayedexpandablewidget.cpp \
    delayedinspectionwidget.cpp \
    gridwidget.cpp

HEADERS += \
        mainwindow.h \
    centralwidget.h \
    expandablewidget.h \
    expandabletreewidget.h \
    Mesh/mesh.h \
    Mesh/vertex.h \
    Mesh/face.h \
    vectorwidget.h \
    Mesh/halfedge.h \
    Mesh/meshwidget.h \
    layoutfactory.h \
    Mesh/vertexwidget.h \
    Mesh/halfedgewidget.h \
    Mesh/facewidget.h \
    Mesh/widgettools.h \
    inspectionwidget.h \
    delayedinspectionwidget.h \
    gridwidget.h

CONFIG += c++14
