#include "meshwidget.h"

#include <QDebug>
#include <QVBoxLayout>
#include <cassert>
#include "Mesh/mesh.h"
#include "expandabletreewidget.h"
#include "expandablewidget.h"
#include "facewidget.h"
#include "halfedgewidget.h"
#include "vectorwidget.h"
#include "vertex.h"
#include "vertexwidget.h"

MeshWidget::MeshWidget(Mesh *mesh, QWidget *parent) : ExpandableTreeWidget(parent), _mesh(mesh) {
  addWidget(new ExpandableWidget(
      new VectorWidget<Vertex, VertexWidget>(_mesh->getVertices(), this), "Vertices", this));
  //  treeWidget->addWidget(new ExpandableWidget(
  //      new VectorWidget<Face, FaceWidget>(_mesh->getFaces(), treeWidget), "Faces", treeWidget));
  //  treeWidget->addWidget(new ExpandableWidget(
  //      new VectorWidget<HalfEdge, HalfEdgeWidget>(_mesh->getHalfEdges(), treeWidget),
  //      "HalfEdges",
  //      treeWidget));

  qDebug() << "Create MeshWidget";
}

MeshWidget::~MeshWidget() {
  qDebug() << "Destroy MeshWidget";
}
