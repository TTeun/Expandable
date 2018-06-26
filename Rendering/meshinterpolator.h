#ifndef MESHINTERPOLATOR_H
#define MESHINTERPOLATOR_H

#include "renderobject.h"

#include "../Mesh/mesh.h"

class MeshInterpolator : public RenderObject {
 public:
  MeshInterpolator(Mesh *mesh1, Mesh *mesh2, size_t quadrant = 0);

  void fillData() override;
  void initialize(QOpenGLFunctions *f) override;
  void render(QOpenGLFunctions *f) override;

  void update() override;
  static double _alpha;

 private:
  void render(Render_Mode renderMode) override;

  Mesh *_mesh1;
  Mesh *_mesh2;

  size_t _renderMode = Render_Mode::Lines;
  size_t _interpolationPoints = 10u;
};

#endif  // MESHINTERPOLATOR_H
