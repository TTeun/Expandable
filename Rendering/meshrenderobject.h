#ifndef MESHRENDEROBJECT_H
#define MESHRENDEROBJECT_H

#include "renderobject.h"

class PointShader;

class MeshRenderObject : public RenderObject {
 public:
  MeshRenderObject(const Mesh *mesh);

  size_t objectCount() override;
  void fillData() override;
  void initialize(QOpenGLFunctions *f) override;
  void render(QOpenGLFunctions *f) override;

  static size_t getAvailableRenderModes() {
    return _availableRenderModes;
  }

  void toggleRenderMode(Render_Mode renderMode, bool value);
  size_t getRenderMode() {
    return _renderMode;
  }

 private:
  void render(RenderObject::Render_Mode renderMode) override;

  const Mesh *_mesh;

  std::unique_ptr<PointShader> _pointShader;

  size_t _renderMode = Render_Mode::Points | Render_Mode::Lines;
  static const size_t _availableRenderModes = Render_Mode::Points | Render_Mode::Lines;
};

#endif  // MESHRENDEROBJECT_H
