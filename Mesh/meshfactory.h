#ifndef MESHFACTORY_H
#define MESHFACTORY_H

#include <memory>

class Mesh;

class MeshFactory {
 public:
  MeshFactory() = delete;

  static std::unique_ptr<Mesh> buildNGon(size_t n);
  static std::unique_ptr<Mesh> buildTwoSquares();
  static std::unique_ptr<Mesh> buildTwoSquares_Moved();
};

#endif  // MESHFACTORY_H
