#include "vertex.h"

Vertex::Vertex() {
}

size_t Vertex::getIndex() const {
  return _index;
}

double Vertex::getX() const {
  return _x;
}

void Vertex::setX(double x) {
  _x = x;
}

double Vertex::getY() const {
  return _y;
}

void Vertex::setY(double y) {
  _y = y;
}
