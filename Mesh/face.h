#ifndef FACE_H
#define FACE_H

#include "halfedge.h"

#include <cstddef>

class QString;

class Face {
 public:
  Face();

  static const QString &getName();

  size_t getVal() const;
  size_t getIndex() const;
  void setSide(HalfEdge *side) {
    _side = side;
  }

  void setVal(size_t val) {
    _val = val;
  }

  void setIndex(size_t index) {
    _index = index;
  }

  const HalfEdge *getSide() const;

 private:
  HalfEdge *_side;
  size_t _val = 0;
  size_t _index = 0u;
};

#endif  // FACE_H
