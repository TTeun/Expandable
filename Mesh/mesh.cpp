#include "Mesh/mesh.h"

#include <QString>

Mesh::Mesh() : _vertices(3), _faces(5), _halfEdges(2) {
  _vertices[0] = Vertex(.1, 0.1, 0);
  _vertices[1] = Vertex(0.2, 0.2, 1);
  _vertices[2] = Vertex(.3, 0.3, 2);

  _halfEdges[0].setTarget(&_vertices[0]);
  _halfEdges[1].setTarget(&_vertices[1]);
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
