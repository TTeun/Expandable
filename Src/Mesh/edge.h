#ifndef EDGE_H
#define EDGE_H

#include <cstddef>
#include <limits>

class Vertex;
class QString;

class Edge {
 public:
  Edge();

  static const QString& getName();

  size_t getIndex() const;

  const Vertex* getTarget() const;
  Vertex* getTarget();

  void setTarget(Vertex* target);

  void setNext(Edge* next) {
    _next = next;
    next->_prev = this;
  }

  Edge* getNext();
  const Edge* getNext() const;

  Edge* getPrev();
  const Edge* getPrev() const;

 private:
  Vertex* _target;
  Edge* _next;
  Edge* _prev;
  size_t _index = std::numeric_limits<size_t>::max();
};

#endif  // EDGE_H
