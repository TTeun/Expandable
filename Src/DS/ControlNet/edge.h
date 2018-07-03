#ifndef EDGE_H
#define EDGE_H

#include <cstddef>
#include <limits>

class Vertex;

class Edge {
 public:
  Edge(size_t index = std::numeric_limits<size_t>::max());

  Edge(Edge *next,
       Edge *prev,
       Vertex *target = nullptr,
       size_t index = std::numeric_limits<size_t>::max());

  Edge(Vertex *target, size_t index);

  const Edge *next() const;
  Edge *next();
  void setNext(Edge *next);

  const Edge *prev() const;
  Edge *prev();
  void setPrev(Edge *prev);

  size_t getIndex() const;
  void setIndex(const size_t &value);

 private:
  Edge *_next = nullptr;
  Edge *_prev = nullptr;
  Vertex *_target;
  size_t _index;
};

#endif  // EDGE_H
