#ifndef MESH_H
#define MESH_H

#include <memory>
#include <vector>
#include "face.h"
#include "halfedge.h"
#include "vertex.h"

class Mesh {
 public:
  Mesh();

  const std::vector<Vertex> &getVertices() const;
  std::vector<Vertex> &getVertices();
  const std::vector<Face> &getFaces() const;
  std::vector<Face> &getFaces();
  const std::vector<HalfEdge> &getHalfEdges() const;
  std::vector<HalfEdge> &getHalfEdges();

 private:
  std::vector<Vertex> _vertices;
  std::vector<Face> _faces;
  std::vector<HalfEdge> _halfEdges;
};

#endif  // MESH_H
