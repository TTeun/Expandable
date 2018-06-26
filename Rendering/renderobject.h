#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include "../Mesh/mesh.h"
#include "../Shaders/pointshader.h"

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QVector4D>
#include <QVector>

class RenderObject {
 public:
  enum Render_Mode : size_t { Points = 1u, Lines = 2u, End = 4u };
  enum Render_Position { Top_Left, Bottom_Left, Right, Whole };

  static QString getNameOfRenderMode(Render_Mode renderMode);

  RenderObject(Render_Position renderPosition = Whole);

  virtual ~RenderObject() {
  }
  bool isInitialized() {
    return _isInitialized;
  }

  void setQuadrant(size_t quadrant);

  virtual void render(QOpenGLFunctions *f);
  virtual size_t objectCount();
  virtual void initialize(QOpenGLFunctions *f);
  virtual void update();
  virtual void fillData();
  virtual void cleanUp();

  void needsUpdate(bool needsUpdate);
  void toggleRenderMode(RenderObject::Render_Mode renderMode, bool value);
  void setTransform(Render_Position renderPosition);
  void setTransform(float dx, float dy, float scale = 1.0);
  void setColor(float r, float g, float b, float alpha = 1.0);

  std::unique_ptr<PointShader> _pointShader;

 protected:
  void initializeBase(QOpenGLFunctions *f);
  virtual void renderObject(RenderObject::Render_Mode renderMode) = 0;

  bool _uniformsNeedUpdate = true;

  float _dx = 0.;
  float _dy = 0.;
  float _scale;
  QVector4D _color = QVector4D(0., 0., 0., 1.);

  QOpenGLVertexArrayObject _vao;

  QOpenGLBuffer _vertexPositionBufferObject;
  QOpenGLBuffer _vertexNormalBufferObject;
  QOpenGLBuffer _indexBufferObject;

  QVector<GLfloat> _positionData;
  QVector<GLfloat> _normalData;
  QVector<GLushort> _indices;

  size_t _renderMode = Render_Mode::Lines;
  bool _needsUpdate;
  bool _isInitialized = false;
};

#endif  // RENDEROBJECT_H
