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

MeshWidget::MeshWidget(Mesh *mesh, QWidget *parent, RenderObject *renderObject)
    : TreeWidget(parent), _mesh(mesh), _renderObject(renderObject) {
  addWidget(new DelayedExpandableWidget(VectorWidget<Vertex, VertexWidget>::createWidgetBuilder(
                                            &_mesh->getVertices(), this, renderObject),
                                        "Vertices",
                                        this));
  //  addWidget(
  //      new DelayedExpandableWidget(VectorWidget<HalfEdge, HalfEdgeWidget,
  //      Mesh>::createWidgetBuilder(
  //                                      &_mesh->getHalfEdges(), this, mesh),
  //                                  "HalfEdges",
  //                                  this));
  //  addWidget(new DelayedExpandableWidget(
  //      VectorWidget<Face, FaceWidget, Mesh>::createWidgetBuilder(&_mesh->getFaces(), this, mesh),
  //      "Faces",
  //      this));
  qDebug() << "Create MeshWidget";
}

MeshWidget::~MeshWidget() {
  qDebug() << "Destroy MeshWidget";
}
