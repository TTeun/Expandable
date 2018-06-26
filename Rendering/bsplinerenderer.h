#ifndef BSPLINERENDERER_H
#define BSPLINERENDERER_H

#include "renderobject.h"

#include "Shaders/pointshader.h"

class BSplineRenderer : public RenderObject {
 public:
  BSplineRenderer(Mesh* mesh, Render_Position renderPosition = Whole);

  void fillData() override;
  void update() override;

 private:
  void renderObject(Render_Mode renderMode) override;
  Mesh* _mesh;
  size_t _renderMode = Render_Mode::Lines;
  size_t _interpolationPoints = 10u;
};

#endif  // BSPLINERENDERER_H
