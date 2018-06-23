#include "shaderhandler.h"

#include <QOpenGLShaderProgram>

#include <string>

void ShaderHandler::initialize() {
  _pointShader.reset(new PointShader);
}

QOpenGLShaderProgram *ShaderHandler::getShader(RenderObject::Render_Mode renderMode) const {
  switch (renderMode) {
    case RenderObject::Render_Mode::Points:
      return _pointShader->getShader();
    case RenderObject::Render_Mode::Lines:
      return _pointShader->getShader();
    default:
      break;
  }
  throw std::string("No shader returned see ") + std::string(__FILE__);
}
