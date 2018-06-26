#include "meshrenderobject.h"

#include "../Shaders/pointshader.h"

#include <QOpenGLShaderProgram>

MeshRenderObject::MeshRenderObject(const Mesh *mesh, Render_Position renderPosition)
    : RenderObject(renderPosition), _mesh(mesh) {
  _renderMode = Render_Mode::Lines | Render_Mode::Points;
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

void MeshRenderObject::renderObject(RenderObject::Render_Mode renderMode) {
  _pointShader->bind();
  if (_uniformsNeedUpdate) {
    _pointShader->setTransformUniforms(_dx, _dy, _scale);
    _pointShader->setColourUniform(_color[0], _color[1], _color[2], _color[3]);
    _uniformsNeedUpdate = false;
  }
  switch (renderMode) {
    case RenderObject::Render_Mode::Points:
      glPointSize(6);
      glDrawArrays(GL_POINTS, 0, objectCount());
      break;
    case RenderObject::Render_Mode::Lines:
      glDrawArrays(GL_LINE_STRIP, 0, objectCount());
      break;
    case RenderObject::End:
      throw std::string("Using RenderObject::End as enum in renderObject: ") +
          std::string(__FILE__);
  }
  _pointShader->release();
}
