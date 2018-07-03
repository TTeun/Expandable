#include "controlnetfactory.h"

#include "controlnet.h"

ControlNet *ControlNetFactory::createSquare() {
  ControlNet *controlNet = new ControlNet;
  auto &edges = controlNet->getEdges();
  auto &vertices = controlNet->getVertices();

  vertices.push_back(Vertex({-0.5, -0.5}, 0ul));
  vertices.push_back(Vertex({-0.5, 0.5}, 1ul));
  vertices.push_back(Vertex({0.5, 0.5}, 2ul));
  vertices.push_back(Vertex({0.5, -0.5}, 3ul));

  edges.push_back(Edge(&vertices[0ul], 0ul));
  edges.push_back(Edge(&vertices[1ul], 1ul));
  edges.push_back(Edge(&vertices[2ul], 2ul));
  edges.push_back(Edge(&vertices[3ul], 3ul));

  for (size_t i = 0; i != 4; ++i) {
    edges[i].setNext(&edges[(i + 1ul) % 4ul]);
  }

  return controlNet;
}
