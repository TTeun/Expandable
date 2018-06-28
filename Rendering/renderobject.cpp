#include "renderobject.h"

#include "../Shaders/simpleshader.h"
#include "exception.h"

#include <QString>

QString RenderObject::getNameOfRenderMode(RenderObject::Render_Mode renderMode) {
  switch (renderMode) {
    case RenderObject::Render_Mode::Points:
      return QString("Points");
    case RenderObject::Render_Mode::Lines:
      return QString("Lines");
      break;
    default:
      THROW_STRING("RenderObject::Render_Mode error");
      break;
  }
}

bool RenderObject::isInitialized() {
  return _isInitialized;
}

RenderObject::RenderObject(Render_Position renderPosition)
    : _indexBufferObject(QOpenGLBuffer::IndexBuffer) {
  setTransform(renderPosition);
}

RenderObject::~RenderObject() {
}

void RenderObject::render(QOpenGLFunctions *f) {
  if (not _isInitialized) {
    initialize(f);
  }
  update();
  QOpenGLVertexArrayObject::Binder vaoBinder(&_vao);
  for (size_t i = 1u; i != Render_Mode::End; i <<= 1u) {
    if (_renderMode & i) {
      renderObject(static_cast<RenderObject::Render_Mode>(i));
    }
  }
}

void RenderObject::needsUpdate(bool needsUpdate) {
  _needsUpdate = needsUpdate;
}

void RenderObject::setTransform(RenderObject::Render_Position renderPosition) {
  switch (renderPosition) {
    case RenderObject::Top_Left:
      setTransform(-0.5, 0.5, 0.5);
      break;
    case RenderObject::Bottom_Left:
      setTransform(-0.5, -0.5, 0.5);
      break;
    case RenderObject::Top_Right:
      setTransform(0.5, 0.5, 0.5);
      break;
    case RenderObject::Bottom_Right:
      setTransform(0.5, -0.5, 0.5);
      break;
    case RenderObject::Right:
      setTransform(0.5, 0., 0.5);
      break;
    case RenderObject::Whole:
      setTransform(0., 0., 1.);
      break;
    default:
      break;
  }
}

void RenderObject::toggleRenderMode(RenderObject::Render_Mode renderMode, bool value) {
  if (value) {
    _renderMode |= renderMode;
  } else {
    _renderMode &= ~(renderMode);
  }
}

void RenderObject::setTransform(float dx, float dy, float scale) {
  _dx = dx;
  _dy = dy;
  _scale = scale;
  _uniformsNeedUpdate = true;
}

void RenderObject::setColor(float r, float g, float b, float alpha) {
  _color = QVector4D(r, g, b, alpha);
  _uniformsNeedUpdate = true;
}

void RenderObject::initializeBase(QOpenGLFunctions *f) {
  _vao.create();
  QOpenGLVertexArrayObject::Binder vaoBinder(&_vao);
  Q_UNUSED(vaoBinder);
  _vertexPositionBufferObject.create();
  _vertexPositionBufferObject.setUsagePattern(QOpenGLBuffer::StaticDraw);
  _indexBufferObject.create();
  _indexBufferObject.setUsagePattern(QOpenGLBuffer::StaticDraw);
  _needsUpdate = true;
  {
    _vertexPositionBufferObject.bind();
    f->glEnableVertexAttribArray(0);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
    _vertexPositionBufferObject.release();
  }
  _isInitialized = true;
  _pointShader.reset(new SimpleShader);
}

size_t RenderObject::objectCount() {
  return _positionData.size() / 3;
}

void RenderObject::initialize(QOpenGLFunctions *f) {
  initializeBase(f);
}

void RenderObject::update() {
  fillData();
  _vertexPositionBufferObject.bind();
  _vertexPositionBufferObject.allocate(_positionData.constData(),
                                       _positionData.size() * sizeof(GLfloat));
  _indexBufferObject.bind();
  _indexBufferObject.allocate(_indices.constData(), _indices.size() * sizeof(GLushort));
  _indexBufferObject.release();
  _vertexPositionBufferObject.release();
  _needsUpdate = false;
}

void RenderObject::fillData() {
}

void RenderObject::cleanUp() {
  _vertexPositionBufferObject.destroy();
  _indexBufferObject.destroy();
  _vao.destroy();
}
