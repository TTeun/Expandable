#ifndef MESHRENDEROBJECT_H
#define MESHRENDEROBJECT_H

#include "renderobject.h"

class MeshRenderObject : public RenderObject {
 public:
  MeshRenderObject(const Mesh *mesh, Render_Position renderPosition = Whole);

  size_t objectCount() override;
  void fillData() override;

  static size_t getAvailableRenderModes() {
    return _availableRenderModes;
  }

  size_t getRenderMode() {
    return _renderMode;
  }

 private:
  void renderObject(Render_Mode renderMode) override;

  const Mesh *_mesh;

  static const size_t _availableRenderModes = Render_Mode::Points | Render_Mode::Lines;
};

#endif  // MESHRENDEROBJECT_H
