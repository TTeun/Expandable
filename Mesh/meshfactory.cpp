#include "meshfactory.h"

#include "mesh.h"

std::unique_ptr<Mesh> MeshFactory::buildNGon(size_t n) {
  Mesh *mesh = new Mesh;
  auto &vertices = mesh->getVertices();
  auto &halfEdges = mesh->getHalfEdges();
  auto &faces = mesh->getFaces();
  vertices.resize(n);
  halfEdges.resize(n);
  faces.resize(1);
  for (size_t i = 0; i != n; ++i) {
    vertices[i] = (Vertex(cos(i * M_PI * 2. / n), sin(i * M_PI * 2. / n), i));
  }
  for (size_t i = 0; i != n; ++i) {
    halfEdges[i].setTarget(&vertices[i]);
    halfEdges[i].setNext(&halfEdges[(i + 1u) % n]);
  }
  faces[0].setVal(n);
  faces[0].setSide(&halfEdges[0]);
  return std::unique_ptr<Mesh>(mesh);
}

std::unique_ptr<Mesh> MeshFactory::buildTwoSquares() {
  Mesh *mesh = new Mesh;
  auto &vertices = mesh->getVertices();
  auto &halfEdges = mesh->getHalfEdges();
  auto &faces = mesh->getFaces();
  vertices.resize(8);
  halfEdges.resize(8);
  faces.resize(2);

  for (size_t i = 0; i != 4; ++i) {
    vertices[i] = (Vertex(0.5 * cos(i * M_PI * 2. / 4.) + 0.5, 0.5 * sin(i * M_PI * 2. / 4.), i));
  }
  for (size_t i = 0; i != 4; ++i) {
    vertices[i + 4] =
        (Vertex(0.5 * cos(i * M_PI * 2. / 4.) - 0.5, 0.5 * sin(i * M_PI * 2. / 4.), i));
  }
  vertices[1].setX(0);
  vertices[3].setX(0);
  vertices[5].setX(0);
  vertices[7].setX(0);
  for (size_t i = 0; i != 4; ++i) {
    halfEdges[i].setTarget(&vertices[i]);
    halfEdges[i].setNext(&halfEdges[(i + 1u) % 4]);
  }
  for (size_t i = 0; i != 4; ++i) {
    halfEdges[i + 4].setTarget(&vertices[i + 4]);
    halfEdges[i + 4].setNext(&halfEdges[((i + 1u) % 4) + 4]);
  }
  faces[0].setVal(4);
  faces[0].setSide(&halfEdges[0]);
  faces[1].setVal(4);
  faces[1].setSide(&halfEdges[5]);
  return std::unique_ptr<Mesh>(mesh);
}

std::unique_ptr<Mesh> MeshFactory::buildTwoSquares_Moved() {
  Mesh *mesh = new Mesh;
  auto &vertices = mesh->getVertices();
  auto &halfEdges = mesh->getHalfEdges();
  auto &faces = mesh->getFaces();
  vertices.resize(8);
  halfEdges.resize(8);
  faces.resize(2);

  for (size_t i = 0; i != 4; ++i) {
    vertices[i] = (Vertex(0.5 * cos(i * M_PI * 2. / 4.) + 0.5, 0.5 * sin(i * M_PI * 2. / 4.), i));
  }
  for (size_t i = 0; i != 4; ++i) {
    vertices[i + 4] =
        (Vertex(0.5 * cos(i * M_PI * 2. / 4.) - 0.5, 0.5 * sin(i * M_PI * 2. / 4.), i));
  }
  vertices[1].setX(0);
  vertices[3].setX(0);
  vertices[5].setX(0);
  vertices[7].setX(0);
  for (size_t i = 0; i != 4; ++i) {
    halfEdges[i].setTarget(&vertices[i]);
    halfEdges[i].setNext(&halfEdges[(i + 1u) % 4]);
  }

  for (size_t i = 0; i != 4; ++i) {
    halfEdges[i + 4].setTarget(&vertices[i + 4]);
    halfEdges[i + 4].setNext(&halfEdges[((i + 1u) % 4) + 4]);
  }
  faces[0].setVal(4);
  faces[0].setSide(&halfEdges[0]);
  faces[1].setVal(4);
  faces[1].setSide(&halfEdges[5]);

  const double x = 0.3;
  vertices[1].setX(x);
  vertices[2].setX(x);
  vertices[3].setX(x);

  vertices[4].setX(-x);
  vertices[5].setX(-x);
  vertices[7].setX(-x);
  return std::unique_ptr<Mesh>(mesh);
}
