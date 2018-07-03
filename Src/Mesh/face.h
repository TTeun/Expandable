#ifndef FACE_H
#define FACE_H

#include <cstddef>
#include <limits>

class QString;
class Edge;

class Face {
 public:
  Face();

  static const QString &getName();

  size_t getVal() const;
  size_t getIndex() const;
  void setSide(Edge *side);
  void setVal(size_t val);
  void setIndex(size_t index);
  const Edge *getSide() const;

 private:
  Edge *_side;
  size_t _val = 0;
  size_t _index = std::numeric_limits<size_t>::max();
};

#endif  // FACE_H
