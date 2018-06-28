#ifndef MESHINTERPOLATIONSURFACE_H
#define MESHINTERPOLATIONSURFACE_H

#include "renderobject.h"

class Mesh;

class MeshInterpolationSurface : public RenderObject {
 public:
  MeshInterpolationSurface(Mesh *mesh1, Mesh *mesh2, Render_Position renderPosition = Whole);

  void fillData() override;

 private:
  void renderObject(Render_Mode renderMode) override;

  Mesh *_mesh1;
  Mesh *_mesh2;

  size_t _slices = 30u;

  size_t _interpolationPoints = 6u;
};

#endif  // MESHINTERPOLATIONSURFACE_H
