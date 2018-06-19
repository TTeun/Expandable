#ifndef VERTEXWIDGET_H
#define VERTEXWIDGET_H

#include <functional>
#include "gridwidget.h"
#include "inspectionwidget.h"

class Vertex;
class VertexWidget;

class VertexWidget : public GridWidget, public InspectionWidget<Vertex, VertexWidget> {
  Q_OBJECT
 public:
  VertexWidget(Vertex *vertex, QWidget *parent);

 public:
  ~VertexWidget();

 public slots:
  void setX(const double x);
  void setY(const double y);

 private:
  Vertex *_vertex;
};

#endif  // VERTEXWIDGET_H
