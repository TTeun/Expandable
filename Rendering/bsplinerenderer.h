#ifndef BSPLINERENDERER_H
#define BSPLINERENDERER_H

#include "renderobject.h"

#include "Shaders/pointshader.h"

class BSplineRenderer : public RenderObject {
 public:
  BSplineRenderer(Mesh* mesh, size_t quadrant = 0);

  void fillData() override;
  void initialize(QOpenGLFunctions* f) override;
  void render(QOpenGLFunctions* f) override;

  void update() override;

 private:
  void render(Render_Mode renderMode) override;
  Mesh* _mesh;
  size_t _renderMode = Render_Mode::Lines;
  size_t _interpolationPoints = 10u;
};

#endif  // BSPLINERENDERER_H
