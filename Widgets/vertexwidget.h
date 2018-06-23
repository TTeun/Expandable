#ifndef VERTEXWIDGET_H
#define VERTEXWIDGET_H

#include "../Mesh/mesh.h"
#include "gridwidget.h"
#include "inspectionwidgetwithparent.h"

class Vertex;

class VertexWidget : public GridWidget,
                     public InspectionWidgetWithParent<Vertex, VertexWidget, Mesh> {
  Q_OBJECT
 public:
  VertexWidget(Vertex *vertex, QWidget *parent, Mesh *parentObject);

 public:
  ~VertexWidget();

 signals:
  void wasUpdated(const Mesh *ptr);

 public slots:
  void setX(const double x);
  void setY(const double y);
  void setZ(const double z);

 private:
  Mesh *_parentObject = nullptr;
  Vertex *_vertex;
};

#endif  // VERTEXWIDGET_H
