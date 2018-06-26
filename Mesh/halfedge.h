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

  const Vertex* getTarget() const;
  Vertex* getTarget();

  void setTarget(Vertex* target);

  void setNext(HalfEdge* next) {
    _next = next;
    next->_prev = this;
  }

  HalfEdge* getNext();
  const HalfEdge* getNext() const;

  HalfEdge* getPrev();
  const HalfEdge* getPrev() const;

 private:
  Vertex* _target;
  HalfEdge* _next;
  HalfEdge* _prev;
  size_t _index = 0u;
};

#endif  // EDGE_H
