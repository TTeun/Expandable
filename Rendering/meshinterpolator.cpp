#include "meshinterpolator.h"

#include <QVector2D>
#include <QtGlobal>

double MeshInterpolator::_alpha = 0.5f;

MeshInterpolator::MeshInterpolator(Mesh *mesh1, Mesh *mesh2, Render_Position renderPosition)
    : RenderObject(renderPosition), _mesh1(mesh1), _mesh2(mesh2) {
  setColor(0.5, 0.5, 0.5);
}

static QVector2D evaluate(const HalfEdge &halfEdge, double param) {
  const Vertex *vertex[4] = {halfEdge.getPrev()->getPrev()->getTarget(),
                             halfEdge.getPrev()->getTarget(),
                             halfEdge.getTarget(),
                             halfEdge.getNext()->getTarget()};
  const double t[4] = {param * param * param, param * param, param, 1};
  const double vec[4] = {-t[0] + 3. * t[1] - 3. * t[2] + t[3],
                         3. * t[0] - 6. * t[1] + 4. * t[3],
                         -3. * t[0] + 3. * t[1] + 3. * t[2] + t[3],
                         t[0]};
  return QVector2D((vec[0] * vertex[0]->getX() + vec[1] * vertex[1]->getX() +
                    vec[2] * vertex[2]->getX() + vec[3] * vertex[3]->getX()) /
                       6.,
                   (vec[0] * vertex[0]->getY() + vec[1] * vertex[1]->getY() +
                    vec[2] * vertex[2]->getY() + vec[3] * vertex[3]->getY()) /
                       6.);
}

void MeshInterpolator::fillData() {
  _positionData.clear();
  _positionData.squeeze();
  _normalData.clear();
  _normalData.squeeze();
  size_t index = 0;
  for (size_t edgeIndex = 0; edgeIndex != _mesh1->getHalfEdges().size(); ++edgeIndex) {
    const double alpha = qBound(0., _alpha, 1.);
    const double x = qBound(0., _alpha - 1., 1.) * 0.3;
    _mesh2->getVertices()[1].setX(x);
    _mesh2->getVertices()[2].setX(x);
    _mesh2->getVertices()[3].setX(x);

    _mesh2->getVertices()[4].setX(-x);
    _mesh2->getVertices()[5].setX(-x);
    _mesh2->getVertices()[7].setX(-x);

    size_t edgeIndex2 = edgeIndex;
    if (edgeIndex < 3) {
      edgeIndex2 = edgeIndex;
    } else if (edgeIndex < 6) {
      edgeIndex2 = edgeIndex + 2;
    } else if (edgeIndex == 6) {
      edgeIndex2 = 4;
    } else {
      edgeIndex2 = 3;
    }
    for (size_t i = 0; i <= _interpolationPoints; ++i) {
      const double param = static_cast<double>(i) / _interpolationPoints;
      const auto pos1 = evaluate(_mesh1->getHalfEdges()[edgeIndex], param);
      const auto pos2 = evaluate(_mesh2->getHalfEdges()[edgeIndex2], param);
      _positionData.append((1. - alpha) * pos1.x() + alpha * pos2.x());
      _positionData.append((1. - alpha) * pos1.y() + alpha * pos2.y());
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
  //  _mesh2->getVertices()[1].setX(0);
  //  _mesh2->getVertices()[2].setX(0);
  //  _mesh2->getVertices()[3].setX(0);
  //  _mesh2->getVertices()[4].setX(0);
  //  _mesh2->getVertices()[5].setX(0);
  //  _mesh2->getVertices()[7].setX(0);
}

void MeshInterpolator::update() {
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

void MeshInterpolator::renderObject(RenderObject::Render_Mode renderMode) {
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
  _pointShader->release();
}
