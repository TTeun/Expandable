#ifndef MESHRENDEROBJECT_H
#define MESHRENDEROBJECT_H

#include "renderobject.h"

class MeshRenderObject : public RenderObject {
 public:
  MeshRenderObject(const Mesh *mesh);

  void fillData() override;

 private:
  const Mesh *_mesh;
};

#endif  // MESHRENDEROBJECT_H
