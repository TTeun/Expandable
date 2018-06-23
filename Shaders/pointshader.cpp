#include "pointshader.h"

#include <QOpenGLShaderProgram>

static const char *vertexShaderSource =
    "attribute vec3 position;\n"
    "attribute vec3 normal;\n"
    "varying vec3 vert;\n"
    "void main() {\n"
    "   gl_Position =  vec4(position,1.0);\n"
    "}\n";

static const char *fragmentShaderSource =
    "varying highp vec3 vert;\n"
    "void main() {\n"
    "   gl_FragColor = vec4(0.0,0.0,0.0, 1.0);\n"
    "}\n";

PointShader::PointShader() : _shader(std::make_unique<QOpenGLShaderProgram>()) {
  _shader->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
  _shader->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
  _shader->bindAttributeLocation("position", 0);
  _shader->bindAttributeLocation("normal", 1);
  _shader->link();
}

QOpenGLShaderProgram *PointShader::getShader() {
  return _shader.get();
}

void PointShader::bind() {
  _shader->bind();
}

void PointShader::release() {
  _shader->release();
}
