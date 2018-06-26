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

  void setQuadrant(size_t quadrant);

 private:
  std::unique_ptr<QOpenGLShaderProgram> _shader;

  int _dxLocation;
  int _dyLocation;
  int _scaleLocation;
};

#endif  // POINTSHADER_H
