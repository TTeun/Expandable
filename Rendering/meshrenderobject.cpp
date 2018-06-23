#include "meshrenderobject.h"

MeshRenderObject::MeshRenderObject(const Mesh *mesh) : _mesh(mesh) {
}

void MeshRenderObject::fillData() {
  _data.clear();
  _data.squeeze();
  for (auto &vertex : _mesh->getVertices()) {
    _data.append(vertex.getX() + 0.5);
    _data.append(vertex.getY());
    _data.append(0.05);

    _data.append(0.);
    _data.append(0.);
    _data.append(-1);
  }
}
