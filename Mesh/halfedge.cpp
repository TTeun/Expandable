#include "halfedge.h"

HalfEdge::HalfEdge() {
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
