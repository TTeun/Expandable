#include "meshrenderobject.h"

#include "Debug/exceptiondefines.h"
#include "Shaders/simpleshader.h"

#include <QOpenGLShaderProgram>

MeshRenderObject::MeshRenderObject(const Mesh *mesh, Render_Position renderPosition)
    : RenderObject(renderPosition), _mesh(mesh) {
  _renderMode = Render_Mode::Lines | Render_Mode::Points;
  setColour(0.7, 0.7, 0.7);
}

size_t MeshRenderObject::objectCount() {
  return _positionData.size() / 3;
}

void MeshRenderObject::fillData() {
  _positionData.clear();
  _positionData.squeeze();
  _indices.clear();
  _indices.squeeze();
  size_t index = 0;
  for (const auto &face : _mesh->getFaces()) {
    auto *side = face.getSide();
    for (size_t i = 0; i != face.getVal() + 1u; ++i) {
      if (i != face.getVal()) {
        _indices.append(index);
        _indices.append(index + 1);
      }
      ++index;
      const auto *vertex = side->getTarget();
      _positionData.append(vertex->getX());
      _positionData.append(vertex->getY());
      _positionData.append(vertex->getZ());
      side = side->getNext();
    }
  }
}

size_t MeshRenderObject::getAvailableRenderModes() {
  return _availableRenderModes;
}

size_t MeshRenderObject::getRenderMode() {
  return _renderMode;
}

void MeshRenderObject::renderObject(RenderObject::Render_Mode renderMode) {
  _simpleShader->bind();
  if (_uniformsNeedUpdate) {
    _simpleShader->setTransform(_dx, _dy, _scale);
    _simpleShader->setColour(_color[0], _color[1], _color[2], _color[3]);
    _uniformsNeedUpdate = false;
  }
  _indexBufferObject.bind();
  switch (renderMode) {
    case RenderObject::Render_Mode::Points:
      glPointSize(6);
      glDrawArrays(GL_POINTS, 0, objectCount());
      break;
    case RenderObject::Render_Mode::Lines:
      glDrawElements(GL_LINES, _indices.size(), GL_UNSIGNED_SHORT, 0);
      break;
    default:
      THROW_STRING("RenderObject::Render_Mode error");
  }
  _simpleShader->release();
}
