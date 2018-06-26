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

  void setTransformUniforms(float dx, float dy, float scale);
  void setColourUniform(float r, float g, float b, float alpha = 1.f);

 private:
  std::unique_ptr<QOpenGLShaderProgram> _shader;

  int _dxLocation;
  int _dyLocation;
  int _scaleLocation;
  int _colorLocation;
};

#endif  // POINTSHADER_H
