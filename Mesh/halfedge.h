#ifndef EDGE_H
#define EDGE_H

#include <cstddef>

class Vertex;
class QString;

class HalfEdge {
 public:
  HalfEdge();

  static const QString& getName();

  size_t getIndex() const;

  Vertex* getTarget();

  void setTarget(Vertex* target);

 private:
  Vertex* _target = nullptr;
  size_t _index = 0u;
};

#endif  // EDGE_H
