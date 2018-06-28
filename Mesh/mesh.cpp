#include "Mesh/mesh.h"

#include <QString>

#include <cmath>

Mesh::Mesh() {
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

QVector2D Mesh::evaluateCubicBSpline(const HalfEdge &halfEdge, const double param) {
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
