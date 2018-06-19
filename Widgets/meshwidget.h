#ifndef MESHWIDGET_H
#define MESHWIDGET_H

#include <QWidget>
#include <functional>
#include "treewidget.h"
#include "inspectionwidget.h"

class Mesh;
class MeshWidget;

class MeshWidget : public TreeWidget, public InspectionWidget<Mesh, MeshWidget> {
  Q_OBJECT

 public:
  MeshWidget(Mesh *mesh, QWidget *parent);

 public:
  ~MeshWidget();

 private:
  Mesh *_mesh = nullptr;
};

#endif  // MESHWIDGET_H
