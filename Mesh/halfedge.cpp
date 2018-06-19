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

Vertex *HalfEdge::getTarget() {
  return _target;
}

void HalfEdge::setTarget(Vertex *target) {
  _target = target;
}
