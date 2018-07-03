#include "vertex.h"

Vertex::Vertex(const QVector2D &position, size_t index) : QVector2D(position), _index(index) {
}

size_t Vertex::index() const {
  return _index;
}

void Vertex::setIndex(const size_t &index) {
  _index = index;
}
