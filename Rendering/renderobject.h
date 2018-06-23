#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include "../Mesh/mesh.h"

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QVector>

class RenderObject {
 public:
  enum Render_Mode : size_t { Points = 1u, Lines = 2u, End = 4u };

  static QString getNameOfRenderMode(Render_Mode renderMode);

  RenderObject();

  virtual ~RenderObject() {
  }
  bool isInitialized() {
    return _isInitialized;
  }

  virtual void render(QOpenGLFunctions *f);
  virtual size_t objectCount();
  virtual void initialize(QOpenGLFunctions *f);
  virtual void update();
  virtual void fillData();
  virtual void cleanUp();

  void needsUpdate(bool needsUpdate);

 protected:
  void initializeBase(QOpenGLFunctions *f);
  virtual void render(Render_Mode renderMode) = 0;

  QOpenGLVertexArrayObject _vao;
  QOpenGLBuffer _vertexPositionBufferObject;
  QOpenGLBuffer _vertexNormalBufferObject;
  QVector<GLfloat> _positionData;
  QVector<GLfloat> _normalData;
  size_t _renderMode = Render_Mode::Points | Render_Mode::Lines;
  bool _needsUpdate;
  bool _isInitialized = false;
};

#endif  // RENDEROBJECT_H
