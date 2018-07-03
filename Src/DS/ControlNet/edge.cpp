#include "edge.h"

Edge::Edge(size_t index) : _index(index) {
}

Edge::Edge(Edge *next, Edge *prev, Vertex *target, size_t index)
    : _next(next), _prev(prev), _target(target), _index(index) {
}

Edge::Edge(Vertex *target, size_t index) : _target(target), _index(index) {
}

const Edge *Edge::next() const {
  return _next;
}

Edge *Edge::next() {
  return _next;
}

void Edge::setNext(Edge *next) {
  _next = next;
  _next->_prev = this;
}

const Edge *Edge::prev() const {
  return _prev;
}

Edge *Edge::prev() {
  return _prev;
}

void Edge::setPrev(Edge *prev) {
  _prev = prev;
  _prev->_next = this;
}

size_t Edge::getIndex() const {
  return _index;
}

void Edge::setIndex(const size_t &value) {
  _index = value;
}
