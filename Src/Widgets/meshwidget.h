#ifndef MESHWIDGET_H
#define MESHWIDGET_H

#include "inspectionwidget.h"
#include "treewidget.h"

class Mesh;
class RenderObject;

class MeshWidget : public TreeWidget, public InspectionWidget<Mesh, MeshWidget> {
  Q_OBJECT

 public:
  MeshWidget(Mesh *mesh, QWidget *parent, RenderObject *renderObject);

 public:
  ~MeshWidget();

 signals:
  void wasUpdated();

 private:
  Mesh *_mesh = nullptr;
  RenderObject *_renderObject;
};

#endif  // MESHWIDGET_H
