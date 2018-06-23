#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include "../Mesh/mesh.h"

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QVector>

class RenderObject {
 public:
  RenderObject();

  virtual ~RenderObject() {
  }

  void initialize(QOpenGLFunctions *f);
  void update();
  virtual void fillData();
  void cleanUp();

 public:
  QOpenGLVertexArrayObject _vao;
  QOpenGLBuffer _vbo;
  QVector<GLfloat> _data;
  Mesh _mesh;
};

#endif  // RENDEROBJECT_H
