#include "halfedge.h"

#include <QString>

HalfEdge::HalfEdge() {
}

const QString &HalfEdge::getName() {
  static const auto name = QString("HalfEdge");
  return name;
}

size_t HalfEdge::getIndex() const {
  return _index;
}

const Vertex *HalfEdge::getTarget() const {
  return _target;
}

Vertex *HalfEdge::getTarget() {
  return _target;
}

void HalfEdge::setTarget(Vertex *target) {
  _target = target;
}

HalfEdge *HalfEdge::getNext() {
  return _next;
}

const HalfEdge *HalfEdge::getNext() const {
  return _next;
}

HalfEdge *HalfEdge::getPrev() {
  return _prev;
}

const HalfEdge *HalfEdge::getPrev() const {
  return _prev;
}
