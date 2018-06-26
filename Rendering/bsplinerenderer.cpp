#include "bsplinerenderer.h"

BSplineRenderer::BSplineRenderer(Mesh *mesh, Render_Position renderPosition)
    : RenderObject(renderPosition), _mesh(mesh) {
  setColor(0.5, 0.5, 0.5);
}

void BSplineRenderer::fillData() {
  _positionData.clear();
  _positionData.squeeze();
  _normalData.clear();
  _normalData.squeeze();
  size_t index = 0;
  for (const HalfEdge &halfEdge : _mesh->getHalfEdges()) {
    const Vertex *vertex[4] = {halfEdge.getTarget(),
                               halfEdge.getNext()->getTarget(),
                               halfEdge.getNext()->getNext()->getTarget(),
                               halfEdge.getNext()->getNext()->getNext()->getTarget()};
    for (size_t i = 0; i <= _interpolationPoints; ++i) {
      const double param = static_cast<double>(i) / _interpolationPoints;
      const double t[4] = {param * param * param, param * param, param, 1};
      const double vec[4] = {
          -t[0] + 3. * t[1] - 3. * t[2] + t[3],
          3. * t[0] - 6. * t[1] + 4. * t[3],
          -3. * t[0] + 3. * t[1] + 3. * t[2] + t[3],
          t[0],
      };
      _positionData.append((vec[0] * vertex[0]->getX() + vec[1] * vertex[1]->getX() +
                            vec[2] * vertex[2]->getX() + vec[3] * vertex[3]->getX()) /
                           6.);
      _positionData.append((vec[0] * vertex[0]->getY() + vec[1] * vertex[1]->getY() +
                            vec[2] * vertex[2]->getY() + vec[3] * vertex[3]->getY()) /
                           6.);
      _positionData.append(0);
      _normalData.append(0);
      _normalData.append(0);
      _normalData.append(1);
      if (i != _interpolationPoints) {
        _indices.append(index);
        _indices.append(index + 1);
      }
      ++index;
    }
  }
}

void BSplineRenderer::update() {
  fillData();
  _vertexPositionBufferObject.bind();
  _vertexPositionBufferObject.allocate(_positionData.constData(),
                                       _positionData.size() * sizeof(GLfloat));

  _indexBufferObject.bind();
  _indexBufferObject.allocate(_indices.constData(), _indices.size() * sizeof(GLushort));
  _indexBufferObject.release();

  _vertexPositionBufferObject.release();
  _vertexNormalBufferObject.bind();
  _vertexNormalBufferObject.allocate(_normalData.constData(), _normalData.size() * sizeof(GLfloat));
  _vertexNormalBufferObject.release();
  _needsUpdate = false;
}

void BSplineRenderer::renderObject(RenderObject::Render_Mode renderMode) {
  _pointShader->bind();
  if (_uniformsNeedUpdate) {
    _pointShader->setTransformUniforms(_dx, _dy, _scale);
    _pointShader->setColourUniform(_color[0], _color[1], _color[2], _color[3]);
    _uniformsNeedUpdate = false;
  }
  _indexBufferObject.bind();
  switch (renderMode) {
    case RenderObject::Render_Mode::Points:
      glPointSize(6);
      glDrawArrays(GL_POINTS, 0, _positionData.size() / 3);
      break;
    case RenderObject::Render_Mode::Lines:
      glDrawElements(GL_LINES, _indices.size(), GL_UNSIGNED_SHORT, 0);
      break;
  }
  _indexBufferObject.release();
  _pointShader->release();
}
