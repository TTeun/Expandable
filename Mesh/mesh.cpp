#include "Mesh/mesh.h"

#include <QString>

#include <cmath>

Mesh::Mesh(Preset preset) {
  switch (preset) {
    case Octagon:
      _vertices.resize(8);
      _halfEdges.resize(8);
      _faces.resize(1);

      for (size_t i = 0; i != 8; ++i) {
        _vertices[i] = (Vertex(cos(i * M_PI * 2. / 8.), sin(i * M_PI * 2. / 8.), i));
      }

      for (size_t i = 0; i != 8; ++i) {
        _halfEdges[i].setTarget(&_vertices[i]);
        _halfEdges[i].setNext(&_halfEdges[(i + 1u) % 8]);
      }

      _faces[0].setVal(8);
      _faces[0].setSide(&_halfEdges[0]);
      break;
    case TwoSquares:
      _vertices.resize(8);
      _halfEdges.resize(8);
      _faces.resize(2);
      for (size_t i = 0; i != 4; ++i) {
        _vertices[i] =
            (Vertex(0.5 * cos(i * M_PI * 2. / 4.) + 0.5, 0.5 * sin(i * M_PI * 2. / 4.), i));
      }
      for (size_t i = 0; i != 4; ++i) {
        _vertices[i + 4] =
            (Vertex(0.5 * cos(i * M_PI * 2. / 4.) - 0.5, 0.5 * sin(i * M_PI * 2. / 4.), i));
      }
      _vertices[1].setX(0);
      _vertices[3].setX(0);
      _vertices[5].setX(0);
      _vertices[7].setX(0);
      for (size_t i = 0; i != 4; ++i) {
        _halfEdges[i].setTarget(&_vertices[i]);
        _halfEdges[i].setNext(&_halfEdges[(i + 1u) % 4]);
      }

      for (size_t i = 0; i != 4; ++i) {
        _halfEdges[i + 4].setTarget(&_vertices[i + 4]);
        _halfEdges[i + 4].setNext(&_halfEdges[((i + 1u) % 4) + 4]);
      }
      _faces[0].setVal(4);
      _faces[0].setSide(&_halfEdges[0]);
      _faces[1].setVal(4);
      _faces[1].setSide(&_halfEdges[5]);
      break;
  }
}

const QString &Mesh::getName() {
  static const auto name = QString("Mesh");
  return name;
}

const std::vector<Vertex> &Mesh::getVertices() const {
  return _vertices;
}

std::vector<Vertex> &Mesh::getVertices() {
  return _vertices;
}

const std::vector<Face> &Mesh::getFaces() const {
  return _faces;
}

std::vector<Face> &Mesh::getFaces() {
  return _faces;
}

const std::vector<HalfEdge> &Mesh::getHalfEdges() const {
  return _halfEdges;
}

std::vector<HalfEdge> &Mesh::getHalfEdges() {
  return _halfEdges;
}
