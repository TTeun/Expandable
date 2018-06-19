#include "meshwidget.h"

#include <QDebug>
#include <QVBoxLayout>
#include <cassert>
#include "../Mesh/mesh.h"
#include "../Mesh/vertex.h"
#include "expandabletreewidget.h"
#include "expandablewidget.h"
#include "facewidget.h"
#include "halfedgewidget.h"
#include "vectorwidget.h"
#include "vertexwidget.h"

MeshWidget::MeshWidget(Mesh *mesh, QWidget *parent) : TreeWidget(parent), _mesh(mesh) {
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
