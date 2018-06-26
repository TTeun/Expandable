#include "pointshader.h"

#include <QDebug>
#include <QOpenGLShaderProgram>
#include <QVector4D>

static const char *vertexShaderSource =
    "#version 330\n"
    "attribute vec3 position;\n"
    "attribute vec3 normal;\n"
    "uniform float dx = 0.0f;\n"
    "uniform float dy = 0.0f;\n"
    "uniform float scale = 1.0f;\n"
    "varying vec3 vert;\n"
    "void main() {\n"
    "   vec3 newPos = scale * position;\n"
    "   gl_Position =  vec4(newPos[0] - dx, newPos[1] + dy, newPos[2], 1.0);\n"
    "}\n";

static const char *fragmentShaderSource =
    "#version 330\n"
    "varying highp vec3 vert;\n"
    "uniform vec4 color = vec4(0.f,0.f,0.f,0.f);\n"
    "void main() {\n"
    "   gl_FragColor = color;\n"
    "}\n";

PointShader::PointShader() : _shader(std::make_unique<QOpenGLShaderProgram>()) {
  _shader->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
  _shader->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
  _shader->bindAttributeLocation("position", 0);
  _shader->bindAttributeLocation("normal", 1);
  _shader->link();

  _dxLocation = _shader->uniformLocation("dx");
  _dyLocation = _shader->uniformLocation("dy");
  _scaleLocation = _shader->uniformLocation("scale");
  _colorLocation = _shader->uniformLocation("color");
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

void PointShader::setTransformUniforms(float dx, float dy, float scale) {
  _shader->bind();
  _shader->setUniformValue(_dxLocation, dx);
  _shader->setUniformValue(_dyLocation, dy);
  _shader->setUniformValue(_scaleLocation, scale);
  _shader->release();
}

void PointShader::setColourUniform(float r, float g, float b, float alpha) {
  _shader->bind();
  _shader->setUniformValue(_colorLocation, {r, g, b, alpha});
  _shader->release();
}
