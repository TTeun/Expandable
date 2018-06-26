#include "openglwidget.h"

#include "../Rendering/meshinterpolator.h"

#include <QCoreApplication>
#include <QDebug>
#include <QMouseEvent>

OpenGlWidget::OpenGlWidget(QWidget *parent) : QOpenGLWidget(parent) {
}

OpenGlWidget::~OpenGlWidget() {
  cleanup();
}

QSize OpenGlWidget::minimumSizeHint() const {
  return QSize(50, 50);
}

QSize OpenGlWidget::sizeHint() const {
  return QSize(400, 400);
}

void OpenGlWidget::addRenderObject(RenderObject *renderObject) {
  _renderObjects.push_back(std::unique_ptr<RenderObject>(renderObject));
}

void OpenGlWidget::cleanup() {
  makeCurrent();
  doneCurrent();
}

void OpenGlWidget::initializeGL() {
  qDebug() << "InitializeGl";
  initializeOpenGLFunctions();
  glClearColor(1, 1, 1, 1);
}

void OpenGlWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  for (size_t i = 0; i < _renderObjects.size(); ++i) {
    _renderObjects[i]->render(QOpenGLContext::currentContext()->functions());
  }
}

void OpenGlWidget::resizeGL(int w, int h) {
  //  m_proj.setToIdentity();
  //  m_proj.perspective(45.0f, GLfloat(w) / h, 0.01f, 100.0f);
}
