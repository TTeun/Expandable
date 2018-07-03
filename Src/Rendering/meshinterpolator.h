#ifndef MESHINTERPOLATOR_H
#define MESHINTERPOLATOR_H

#include "renderobject.h"

class Mesh;

class MeshInterpolator : public RenderObject {
 public:
  MeshInterpolator(Mesh *mesh1, Mesh *mesh2, Render_Position renderPosition = Whole);

  void fillData() override;
  static double _alpha;

 private:
  void renderObject(Render_Mode renderMode) override;

  Mesh *_mesh1;
  Mesh *_mesh2;

  size_t _interpolationPoints = 10u;
};

#endif  // MESHINTERPOLATOR_H
