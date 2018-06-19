#ifndef EDGE_H
#define EDGE_H

#include <QString>

class Vertex;

class HalfEdge {
 public:
  HalfEdge();

  static const QString getName() {
    return "HalfEdge";
  }

  size_t getIndex() const;

  Vertex* getTarget();

  void setTarget(Vertex* target);

 private:
  Vertex* _target = nullptr;
  size_t _index = 0u;
};

#endif  // EDGE_H
