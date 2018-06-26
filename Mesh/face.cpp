#include "face.h"

#include <QString>

Face::Face() {
}

const QString &Face::getName() {
  static const auto name = QString("Face");
  return name;
}

size_t Face::getVal() const {
  return _val;
}

size_t Face::getIndex() const {
  return _index;
}

const HalfEdge *Face::getSide() const {
  return _side;
}
