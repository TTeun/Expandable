#ifndef HALFEDGEWIDGET_H
#define HALFEDGEWIDGET_H

#include "gridwidget.h"
#include "inspectionwidgetwithparent.h"

#include <functional>

class HalfEdge;
class Mesh;

class HalfEdgeWidget : public GridWidget,
                       public InspectionWidgetWithParent<HalfEdge, HalfEdgeWidget, Mesh> {
  Q_OBJECT
 public:
  HalfEdgeWidget(HalfEdge *halfEdge, QWidget *parent, Mesh *parentObject);
  ~HalfEdgeWidget();

 signals:
  void wasUpdated(const Mesh *ptr);

 private:
  HalfEdge *_halfEdge;
  Mesh *_parentObject = nullptr;
};

#endif  // HALFEDGEWIDGET_H
