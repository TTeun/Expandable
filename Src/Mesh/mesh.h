#ifndef MESH_H
#define MESH_H

#include <QVector2D>
#include <memory>
#include <vector>

#include "edge.h"
#include "face.h"
#include "vertex.h"

class QString;

class Mesh {
 public:
  Mesh();

  static const QString &getName();

  const std::vector<Vertex> &getVertices() const;
  std::vector<Vertex> &getVertices();

  const std::vector<Face> &getFaces() const;
  std::vector<Face> &getFaces();

  const std::vector<Edge> &getHalfEdges() const;
  std::vector<Edge> &getHalfEdges();

  QVector2D evaluateCubicBSpline(const Edge &halfEdge, const double param);

 private:
  std::vector<Vertex> _vertices;
  std::vector<Face> _faces;
  std::vector<Edge> _halfEdges;
};

#endif  // MESH_H
