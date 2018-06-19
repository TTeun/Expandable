#ifndef HALFEDGEWIDGET_H
#define HALFEDGEWIDGET_H

#include <functional>
#include "gridwidget.h"
#include "inspectionwidget.h"

class HalfEdge;
class HalfEdgeWidget;

class HalfEdgeWidget : public GridWidget, public InspectionWidget<HalfEdge, HalfEdgeWidget> {
  Q_OBJECT
 public:
  HalfEdgeWidget(HalfEdge *halfEdge, QWidget *parent);

 public:
  ~HalfEdgeWidget();

 private:
  HalfEdge *_halfEdge;
};

#endif  // HALFEDGEWIDGET_H
