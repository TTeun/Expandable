#ifndef SIMPLESHADER_H
#define SIMPLESHADER_H

#include <QVector4D>

#include <memory>

class QOpenGLShaderProgram;

class SimpleShader {
 public:
  SimpleShader();

  void bind();
  void release();

  void setTransform(float dx, float dy, float scale);
  void setColour(float r, float g, float b, float alpha = 1.f);

 private:
  void updateUniforms();

  std::unique_ptr<QOpenGLShaderProgram> _shader;

  bool _isInitialized = false;
  bool _uniformsNeedUpdate = true;

  int _dxLocation;
  int _dyLocation;
  int _scaleLocation;
  int _colorLocation;

  float _dx = 0.;
  float _dy = 0.;
  float _scale;
  QVector4D _color = QVector4D(0., 0., 0., 1.);
};

#endif  // SIMPLESHADER_H
