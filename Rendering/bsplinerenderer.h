#ifndef BSPLINERENDERER_H
#define BSPLINERENDERER_H

#include "renderobject.h"

class Mesh;

class BSplineRenderer : public RenderObject {
 public:
  BSplineRenderer(Mesh* mesh, Render_Position renderPosition = Whole);

  void fillData() override;

 private:
  void renderObject(Render_Mode renderMode) override;
  Mesh* _mesh;
  size_t _interpolationPoints = 10u;
};

#endif  // BSPLINERENDERER_H
