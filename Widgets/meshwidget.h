#ifndef MESHWIDGET_H
#define MESHWIDGET_H

#include "inspectionwidget.h"
#include "treewidget.h"

class Mesh;

class MeshWidget : public TreeWidget, public InspectionWidget<Mesh, MeshWidget> {
  Q_OBJECT

 public:
  MeshWidget(Mesh *mesh, QWidget *parent);

 public:
  ~MeshWidget();

 signals:
  void wasUpdated();

 private:
  Mesh *_mesh = nullptr;
};

#endif  // MESHWIDGET_H
