#ifndef HALFEDGEWIDGET_H
#define HALFEDGEWIDGET_H

#include "gridwidget.h"
#include "inspectionwidgetwithparent.h"

#include <functional>

class Edge;
class Mesh;

class HalfEdgeWidget : public GridWidget,
                       public InspectionWidgetWithParent<Edge, HalfEdgeWidget, Mesh> {
  Q_OBJECT
 public:
  HalfEdgeWidget(Edge *halfEdge, QWidget *parent, Mesh *parentObject);
  ~HalfEdgeWidget();

 signals:
  void wasUpdated(const Mesh *ptr);

 private:
  Edge *_halfEdge;
  Mesh *_parentObject = nullptr;
};

#endif  // HALFEDGEWIDGET_H
