#include "edge.h"

#include <QString>

Edge::Edge() {
}

const QString &Edge::getName() {
  static const auto name = QString("HalfEdge");
  return name;
}

size_t Edge::getIndex() const {
  return _index;
}

const Vertex *Edge::getTarget() const {
  return _target;
}

Vertex *Edge::getTarget() {
  return _target;
}

void Edge::setTarget(Vertex *target) {
  _target = target;
}

Edge *Edge::getNext() {
  return _next;
}

const Edge *Edge::getNext() const {
  return _next;
}

Edge *Edge::getPrev() {
  return _prev;
}

const Edge *Edge::getPrev() const {
  return _prev;
}
