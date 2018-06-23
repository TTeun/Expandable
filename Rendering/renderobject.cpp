#include "renderobject.h"

#include <QDebug>

RenderObject::RenderObject() {
}

void RenderObject::initialize(QOpenGLFunctions *f) {
  _vao.create();
  QOpenGLVertexArrayObject::Binder vaoBinder(&_vao);
  Q_UNUSED(vaoBinder);
  _vbo.create();
  update();
  {
    _vbo.bind();
    f->glEnableVertexAttribArray(0);
    f->glEnableVertexAttribArray(1);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
    f->glVertexAttribPointer(1,
                             3,
                             GL_FLOAT,
                             GL_FALSE,
                             6 * sizeof(GLfloat),
                             reinterpret_cast<void *>(3 * sizeof(GLfloat)));
    _vbo.release();
  }
}

void RenderObject::update() {
  fillData();
  _vbo.bind();
  _vbo.allocate(_data.constData(), _data.size() * sizeof(GLfloat));
  _vbo.release();
}

void RenderObject::fillData() {
  _data.clear();
  _data.squeeze();
  for (auto &vertex : _mesh.getVertices()) {
    _data.append(vertex.getX() + 0.5);
    _data.append(vertex.getY());
    _data.append(0.05);

    _data.append(0.);
    _data.append(0.);
    _data.append(-1);
  }
}

void RenderObject::cleanUp() {
  _vbo.destroy();
  _vao.destroy();
}
