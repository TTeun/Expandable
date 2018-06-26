#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include "../Mesh/mesh.h"
#include "../Shaders/pointshader.h"

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QVector>

class RenderObject {
 public:
  enum Render_Mode : size_t { Points = 1u, Lines = 2u, End = 4u };

  static QString getNameOfRenderMode(Render_Mode renderMode);

  RenderObject(size_t quadrant = 0);

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

  std::unique_ptr<PointShader> _pointShader;

 protected:
  size_t _quadrant = 0;

  size_t _dx = 0.;
  size_t _dy = 0.;

  QVector<GLushort> _indices;

  void initializeBase(QOpenGLFunctions *f);
  virtual void render(Render_Mode renderMode) = 0;
  QOpenGLVertexArrayObject _vao;
  QOpenGLBuffer _vertexPositionBufferObject;
  QOpenGLBuffer _vertexNormalBufferObject;
  QOpenGLBuffer _indexBufferObject;
  QVector<GLfloat> _positionData;
  QVector<GLfloat> _normalData;
  size_t _renderMode = Render_Mode::Points | Render_Mode::Lines;
  bool _needsUpdate;
  bool _isInitialized = false;
};

#endif  // RENDEROBJECT_H
