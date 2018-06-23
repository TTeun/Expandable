#include "meshrenderobject.h"

#include "../Shaders/pointshader.h"

#include <QOpenGLShaderProgram>

MeshRenderObject::MeshRenderObject(const Mesh *mesh) : _mesh(mesh) {
}

size_t MeshRenderObject::objectCount() {
  return _positionData.size() / 3;
}

void MeshRenderObject::fillData() {
  _positionData.clear();
  _positionData.squeeze();
  for (auto &vertex : _mesh->getVertices()) {
    _positionData.append(vertex.getX() + 0.5);
    _positionData.append(vertex.getY());
    _positionData.append(vertex.getZ());
  }

  _normalData.clear();
  _normalData.squeeze();
  for (auto &vertex : _mesh->getVertices()) {
    Q_UNUSED(vertex)
    _normalData.append(0);
    _normalData.append(0);
    _normalData.append(1);
  }
}

void MeshRenderObject::initialize(QOpenGLFunctions *f) {
  initializeBase(f);
  _pointShader.reset(new PointShader);
}

void MeshRenderObject::render(QOpenGLFunctions *f) {
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

void MeshRenderObject::toggleRenderMode(RenderObject::Render_Mode renderMode, bool value) {
  if (value) {
    _renderMode |= renderMode;
  } else {
    _renderMode &= ~(renderMode);
  }
}

void MeshRenderObject::render(RenderObject::Render_Mode renderMode) {
  _pointShader->bind();
  switch (renderMode) {
    case RenderObject::Render_Mode::Points:
      glPointSize(6);
      glDrawArrays(GL_POINTS, 0, objectCount());
      break;
    case RenderObject::Render_Mode::Lines:
      glDrawArrays(GL_LINE_STRIP, 0, objectCount());
      break;
  }
  _pointShader->release();
}
