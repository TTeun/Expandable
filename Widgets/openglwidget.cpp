#include "openglwidget.h"
#include <math.h>
#include <QCoreApplication>
#include <QMouseEvent>
#include <QOpenGLShaderProgram>

OpenGlWidget::OpenGlWidget(QWidget *parent) : QOpenGLWidget(parent) {
  _renderObjects.push_back(std::make_unique<RenderObject>());
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

void OpenGlWidget::cleanup() {
  if (m_program == nullptr)
    return;
  makeCurrent();
  delete m_program;
  m_program = nullptr;
  doneCurrent();
}

static const char *vertexShaderSource =
    "attribute vec3 vertex;\n"
    "attribute vec3 normal;\n"
    "varying vec3 vert;\n"
    "void main() {\n"
    "   vert = vertex.xyz;\n"
    "   gl_Position =  vec4(vertex,1.0);\n"
    "}\n";

static const char *fragmentShaderSource =
    "varying highp vec3 vert;\n"
    "varying highp vec3 vertNormal;\n"
    "void main() {\n"
    "   gl_FragColor = vec4(1.0,1.0,1.0, 1.0);\n"
    "}\n";

void OpenGlWidget::initializeGL() {
  initializeOpenGLFunctions();
  glClearColor(0, 0, 0, 1);

  m_program = new QOpenGLShaderProgram;
  m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
  m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
  m_program->bindAttributeLocation("vertex", 0);
  m_program->bindAttributeLocation("normal", 1);
  m_program->link();

  _renderObjects[0]->initialize(QOpenGLContext::currentContext()->functions());
}

void OpenGlWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  QOpenGLVertexArrayObject::Binder vaoBinder(&_renderObjects[0]->_vao);
  m_program->bind();
  glPointSize(20);
  glDrawArrays(GL_POINTS, 0, _renderObjects[0]->_data.size() / 6);
  m_program->release();
}

void OpenGlWidget::resizeGL(int w, int h) {
  //  m_proj.setToIdentity();
  //  m_proj.perspective(45.0f, GLfloat(w) / h, 0.01f, 100.0f);
}
