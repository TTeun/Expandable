#include "meshwidget.h"

#include <QDebug>
#include <QVBoxLayout>
#include <cassert>
#include "../Mesh/mesh.h"
#include "delayedexpandablewidget.h"
#include "facewidget.h"
#include "halfedgewidget.h"
#include "treewidget.h"
#include "vectorwidget.h"
#include "vertexwidget.h"

MeshWidget::MeshWidget(Mesh *mesh, QWidget *parent) : TreeWidget(parent), _mesh(mesh) {
  addWidget(new DelayedExpandableWidget(
      VectorWidget<Vertex, VertexWidget>::createWidgetBuilder(&_mesh->getVertices(), this),
      "Vertices",
      this));
  addWidget(new DelayedExpandableWidget(
      VectorWidget<HalfEdge, HalfEdgeWidget>::createWidgetBuilder(&_mesh->getHalfEdges(), this),
      "HalfEdges",
      this));
  //  addWidget(new DelayedExpandableWidget(
  //      VectorWidget<Vertex, VertexWidget>::createWidgetBuilder(&_mesh->getVertices(), this),
  //      "Vertices",
  //      this));
  qDebug() << "Create MeshWidget";
}

MeshWidget::~MeshWidget() {
  qDebug() << "Destroy MeshWidget";
}
