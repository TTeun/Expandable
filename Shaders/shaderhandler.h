#ifndef SHADERHANDLER_H
#define SHADERHANDLER_H

#include "../Rendering/renderobject.h"
#include "pointshader.h"

#include <memory>

class QOpenGLShaderProgram;

class ShaderHandler {
 public:
  void initialize();

  QOpenGLShaderProgram *getShader(RenderObject::Render_Mode renderMode) const;

 private:
  std::unique_ptr<PointShader> _pointShader;
};

#endif  // SHADERHANDLER_H
