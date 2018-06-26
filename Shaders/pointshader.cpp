#include "pointshader.h"

#include <QDebug>
#include <QOpenGLShaderProgram>

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

  _dxLocation = _shader->uniformLocation("dx");
  _dyLocation = _shader->uniformLocation("dy");
  _scaleLocation = _shader->uniformLocation("scale");
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

void PointShader::setQuadrant(size_t quadrant) {
  _shader->bind();
  switch (quadrant) {
    case 0:
      _shader->setUniformValue(_dxLocation, 0.0f);
      _shader->setUniformValue(_dyLocation, 0.0f);
      _shader->setUniformValue(_scaleLocation, 1.0f);
      break;
    case 1:
      _shader->setUniformValue(_dxLocation, 0.5f);
      _shader->setUniformValue(_dyLocation, 0.5f);
      _shader->setUniformValue(_scaleLocation, 0.4f);
      break;
    case 2:
      _shader->setUniformValue(_dxLocation, 0.5f);
      _shader->setUniformValue(_dyLocation, -0.5f);
      _shader->setUniformValue(_scaleLocation, 0.4f);
      break;
    case 3:
      _shader->setUniformValue(_dxLocation, -0.5f);
      _shader->setUniformValue(_dyLocation, 0.0f);
      _shader->setUniformValue(_scaleLocation, 0.4f);
      break;
  }
  _shader->release();
}
