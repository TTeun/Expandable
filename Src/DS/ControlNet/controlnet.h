#ifndef CONTROLNET_H
#define CONTROLNET_H

#include "edge.h"
#include "vertex.h"

#include <vector>

class ControlNet {
 public:
  ControlNet();

  std::vector<Edge> &getEdges() {
    return _edges;
  }
  std::vector<Vertex> &getVertices() {
    return _vertices;
  }

 private:
  std::vector<Edge> _edges;
  std::vector<Vertex> _vertices;
};

#endif  // CONTROLNET_H
