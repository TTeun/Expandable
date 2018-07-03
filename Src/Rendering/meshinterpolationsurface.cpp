#include "meshinterpolationsurface.h"

#include "Debug/exceptiondefines.h"
#include "Mesh/mesh.h"
#include "Shaders/simpleshader.h"

MeshInterpolationSurface::MeshInterpolationSurface(Mesh *mesh1,
                                                   Mesh *mesh2,
                                                   Render_Position renderPosition)
    : RenderObject(renderPosition), _mesh1(mesh1), _mesh2(mesh2) {
  setColour(0.3, 0.3, 0.3);
  _renderMode = Render_Mode::Lines;
}

double cube(double a) {
  return a * a * a;
}

double scaler(double a) {
  return 0.5 * cube(2 * (a - 0.5)) + 0.5;
}

void MeshInterpolationSurface::fillData() {
  _positionData.clear();
  _positionData.squeeze();
  size_t index = 0;

  for (size_t alphaIndex = 0; alphaIndex != _slices; ++alphaIndex) {
    const double _alpha = scaler(static_cast<double>(alphaIndex) / (_slices - 1));
    const double alpha = 2. * qBound(0., _alpha, 0.5);
    const double x = qBound(0., (alphaIndex / (_slices + 1.)) - 0.5, 0.5) * 0.6;

    for (size_t edgeIndex = 0; edgeIndex != _mesh1->getHalfEdges().size(); ++edgeIndex) {
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
        const auto pos1 = _mesh1->evaluateCubicBSpline(_mesh1->getHalfEdges()[edgeIndex], param);
        const auto pos2 = _mesh2->evaluateCubicBSpline(_mesh2->getHalfEdges()[edgeIndex2], param);
        _positionData.append((1. - alpha) * pos1.x() + alpha * pos2.x());
        _positionData.append(0.5 * ((1. - alpha) * pos1.y() + alpha * pos2.y()) +
                             0.5 * (4.7 * (alphaIndex / (_slices + 1.)) - 2));
        _positionData.append(0);
      }
    }
  }
  size_t offset = _mesh1->getHalfEdges().size() * (_interpolationPoints + 1);
  for (size_t alphaIndex = 0; alphaIndex != _slices; ++alphaIndex) {
    for (size_t edgeIndex = 0; edgeIndex != _mesh1->getHalfEdges().size(); ++edgeIndex) {
      for (size_t i = 0; i <= _interpolationPoints; ++i) {
        if (i != _interpolationPoints) {
          _indices.append(index);
          _indices.append(index + 1);
          if (alphaIndex + 1u != _slices) {
            _indices.append(index);
            _indices.append(index + offset);
          }
        }
        ++index;
      }
    }
  }
  _mesh2->getVertices()[1].setX(0);
  _mesh2->getVertices()[2].setX(0);
  _mesh2->getVertices()[3].setX(0);
  _mesh2->getVertices()[4].setX(0);
  _mesh2->getVertices()[5].setX(0);
  _mesh2->getVertices()[7].setX(0);
}

void MeshInterpolationSurface::renderObject(RenderObject::Render_Mode renderMode) {
  _simpleShader->bind();
  if (_uniformsNeedUpdate) {
    _simpleShader->setTransform(_dx, _dy, _scale);
    _simpleShader->setColour(_color[0], _color[1], _color[2], 0.5);
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
    default:
      THROW_STRING("RenderObject::Render_Mode error");
  }
  _simpleShader->release();
}
