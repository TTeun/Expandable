#ifndef MESHRENDEROBJECT_H
#define MESHRENDEROBJECT_H

#include "renderobject.h"

#include "../Mesh/mesh.h"

class MeshRenderObject : public RenderObject {
 public:
  MeshRenderObject(const Mesh *mesh, Render_Position renderPosition = Whole);

  size_t objectCount() override;
  void fillData() override;

  static size_t getAvailableRenderModes();
  size_t getRenderMode();

 private:
  void renderObject(Render_Mode renderMode) override;

  const Mesh *_mesh;
  static const size_t _availableRenderModes = Render_Mode::Points | Render_Mode::Lines;
};

#endif  // MESHRENDEROBJECT_H
