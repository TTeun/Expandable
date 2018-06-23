#ifndef POINTSHADER_H
#define POINTSHADER_H

#include <memory>

class QOpenGLShaderProgram;

class PointShader {
 public:
  PointShader();

  QOpenGLShaderProgram* getShader();

  void bind();
  void release();

 private:
  std::unique_ptr<QOpenGLShaderProgram> _shader;
};

#endif  // POINTSHADER_H
