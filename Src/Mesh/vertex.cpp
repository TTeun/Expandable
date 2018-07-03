#include "vertex.h"

#include <QString>

Vertex::Vertex() {
}

const QString &Vertex::getName() {
  static const auto name = QString("Vertex");
  return name;
}

size_t Vertex::getIndex() const {
  return _index;
}

double Vertex::getZ() const
{
    return _z;
}

void Vertex::setZ(double z)
{
    _z = z;
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
