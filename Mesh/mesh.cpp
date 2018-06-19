#include "Mesh/mesh.h"

Mesh::Mesh() : _vertices(2), _faces(2), _halfEdges(2) {
  _halfEdges[0].setTarget(&_vertices[0]);
  _halfEdges[1].setTarget(&_vertices[1]);
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
