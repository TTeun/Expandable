#include "meshrenderobject.h"

#include "../Shaders/pointshader.h"

#include <QOpenGLShaderProgram>

MeshRenderObject::MeshRenderObject(const Mesh *mesh, size_t quadrant)
    : RenderObject(quadrant), _mesh(mesh) {
}

size_t MeshRenderObject::objectCount() {
  return _positionData.size() / 3;
}

void MeshRenderObject::fillData() {
  _positionData.clear();
  _positionData.squeeze();
  _normalData.clear();
  _normalData.squeeze();
  for (const auto &face : _mesh->getFaces()) {
    auto *side = face.getSide();
    for (size_t i = 0; i != face.getVal() + 1u; ++i) {
      const auto *vertex = side->getTarget();
      _positionData.append(vertex->getX());
      _positionData.append(vertex->getY());
      _positionData.append(vertex->getZ());

      _normalData.append(0);
      _normalData.append(0);
      _normalData.append(1);
      side = side->getNext();
    }
  }
}

void MeshRenderObject::initialize(QOpenGLFunctions *f) {
  initializeBase(f);
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
