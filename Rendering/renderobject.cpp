#include "renderobject.h"

#include <QDebug>
#include <QString>

QString RenderObject::getNameOfRenderMode(RenderObject::Render_Mode renderMode) {
  switch (renderMode) {
    case RenderObject::Render_Mode::Points:
      return QString("Points");
    case RenderObject::Render_Mode::Lines:
      return QString("Lines");
      break;
    default:
      break;
  }
}

RenderObject::RenderObject(size_t quadrant)
    : _quadrant(quadrant), _indexBufferObject(QOpenGLBuffer::IndexBuffer) {
}

void RenderObject::setQuadrant(size_t quadrant) {
  _pointShader->setQuadrant(quadrant);
}

void RenderObject::render(QOpenGLFunctions *f) {
  if (not _isInitialized) {
    initialize(f);
  }
  update();
  QOpenGLVertexArrayObject::Binder vaoBinder(&_vao);
  for (size_t i = 1u; i != Render_Mode::End; i <<= 1u) {
    if (_renderMode & i) {
      render(static_cast<RenderObject::Render_Mode>(i));
    }
  }
}

void RenderObject::needsUpdate(bool needsUpdate) {
  _needsUpdate = needsUpdate;
}

void RenderObject::initializeBase(QOpenGLFunctions *f) {
  _vao.create();
  QOpenGLVertexArrayObject::Binder vaoBinder(&_vao);
  Q_UNUSED(vaoBinder);
  _vertexPositionBufferObject.create();
  _vertexPositionBufferObject.setUsagePattern(QOpenGLBuffer::StaticDraw);
  _vertexNormalBufferObject.create();
  _vertexNormalBufferObject.setUsagePattern(QOpenGLBuffer::StaticDraw);
  _indexBufferObject.create();
  _indexBufferObject.setUsagePattern(QOpenGLBuffer::StaticDraw);
  _needsUpdate = true;
  {
    _vertexPositionBufferObject.bind();
    f->glEnableVertexAttribArray(0);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
    _vertexPositionBufferObject.release();

    _vertexNormalBufferObject.bind();
    f->glEnableVertexAttribArray(1);
    f->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
    _vertexNormalBufferObject.release();
  }
  _isInitialized = true;
  _pointShader.reset(new PointShader);
  _pointShader->setQuadrant(_quadrant);
}

size_t RenderObject::objectCount() {
  return _positionData.size() / 3;
}

void RenderObject::initialize(QOpenGLFunctions *f) {
  initializeBase(f);
}

void RenderObject::update() {
  if (!_needsUpdate) {
    return;
  }
  fillData();
  _vertexPositionBufferObject.bind();
  _vertexPositionBufferObject.allocate(_positionData.constData(),
                                       _positionData.size() * sizeof(GLfloat));
  _vertexPositionBufferObject.release();
  _vertexNormalBufferObject.bind();
  _vertexNormalBufferObject.allocate(_normalData.constData(), _normalData.size() * sizeof(GLfloat));
  _vertexNormalBufferObject.release();
  _needsUpdate = false;
}

void RenderObject::fillData() {
}

void RenderObject::cleanUp() {
  _vertexPositionBufferObject.destroy();
  _vertexNormalBufferObject.destroy();
  _vao.destroy();
}
