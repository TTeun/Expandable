#include "face.h"
#include "edge.h"

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

void Face::setSide(Edge *side) {
  _side = side;
}

void Face::setVal(size_t val) {
  _val = val;
}

void Face::setIndex(size_t index) {
  _index = index;
}

const Edge *Face::getSide() const {
  return _side;
}
