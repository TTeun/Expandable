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

INCLUDEPATH += /home/teun/Documents/Qt/Src

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    centralwidget.cpp \
    ../../Src/Mesh/mesh.cpp \
    ../../Src/Mesh/vertex.cpp \
    ../../Src/Mesh/face.cpp \
    ../../Src/Widgets/meshwidget.cpp \
    ../../Src/Widgets/vertexwidget.cpp \
    ../../Src/Widgets/halfedgewidget.cpp \
    ../../Src/Widgets/facewidget.cpp \
    ../../Src/Widgets/widgettools.cpp \
    ../../Src/Widgets/delayedexpandablewidget.cpp \
    ../../Src/Widgets/gridwidget.cpp \
    ../../Src/Widgets/treewidget.cpp \
    ../../Src/Widgets/directexpandablewidget.cpp \
    ../../Src/Widgets/expandablewidget.cpp \
    ../../Src/Widgets/openglwidget.cpp \
    ../../Src/Rendering/renderobject.cpp \
    ../../Src/Rendering/meshrenderobject.cpp \
    ../../Src/Widgets/updatedispatcher.cpp \
    ../../Src/Widgets/viewwidget.cpp \
    ../../Src/Widgets/meshviewwidget.cpp \
    ../../Src/Rendering/bsplinerenderer.cpp \
    ../../Src/Rendering/meshinterpolator.cpp \
    ../../Src/Rendering/meshinterpolationsurface.cpp \
    ../../Src/Mesh/meshfactory.cpp \
    ../../Src/Shaders/simpleshader.cpp \
    ../../Src/Mesh/edge.cpp


HEADERS += \
        mainwindow.h \
    centralwidget.h \
    ../../Src/Mesh/mesh.h \
    ../../Src/Mesh/vertex.h \
    ../../Src/Mesh/face.h \
    ../../Src/Widgets/vectorwidget.h \
    ../../Src/Widgets/meshwidget.h \
    ../../Src/layoutfactory.h \
    ../../Src/Widgets/vertexwidget.h \
    ../../Src/Widgets/halfedgewidget.h \
    ../../Src/Widgets/facewidget.h \
    ../../Src/Widgets/widgettools.h \
    ../../Src/Widgets/inspectionwidget.h \
    ../../Src/Widgets/gridwidget.h \
    ../../Src/Widgets/treewidget.h \
    ../../Src/Widgets/delayedexpandablewidget.h \
    ../../Src/Widgets/directexpandablewidget.h \
    ../../Src/Widgets/expandablewidget.h \
    ../../Src/Widgets/vectorfullcontentswidgetfactory.h \
    ../../Src/Widgets/openglwidget.h \
    ../../Src/Rendering/renderobject.h \
    ../../Src/Rendering/meshrenderobject.h \
    ../../Src/Widgets/inspectionwidgetwithparent.h \
    ../../Src/Widgets/updatedispatcher.h \
    ../../Src/Widgets/viewwidget.h \
    ../../Src/Widgets/meshviewwidget.h \
    ../../Src/Rendering/bsplinerenderer.h \
    ../../Src/Rendering/meshinterpolator.h \
    ../../Src/Rendering/meshinterpolationsurface.h \
    ../../Src/Mesh/meshfactory.h \
    ../../Src/Shaders/simpleshader.h \
    ../../Src/Debug/exceptiondefines.h \
    ../../Src/Mesh/edge.h

CONFIG += c++14 -Wall
