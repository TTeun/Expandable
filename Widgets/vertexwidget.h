#ifndef VERTEXWIDGET_H
#define VERTEXWIDGET_H

#include "../Mesh/mesh.h"
#include "gridwidget.h"
#include "inspectionwidget.h"
#include "updatedispatcher.h"

class Vertex;
class RenderObject;

class VertexWidget : public GridWidget, public InspectionWidget<Vertex, VertexWidget> {
  Q_OBJECT
 public:
  VertexWidget(Vertex *vertex, QWidget *parent, RenderObject *renderObject);

 public:
  ~VertexWidget();

 signals:
  void wasUpdated(UpdateDispatcher::Update_Type type);

 public slots:
  void setX(const double x);
  void setY(const double y);
  void setZ(const double z);

 private:
  Vertex *_vertex;
  RenderObject *_renderObject;
};

#endif  // VERTEXWIDGET_H
