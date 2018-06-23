#include "halfedgewidget.h"

#include "../Mesh/face.h"
#include "../Mesh/halfedge.h"
#include "widgettools.h"

#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

#include <cassert>

HalfEdgeWidget::HalfEdgeWidget(HalfEdge *halfEdge, QWidget *parent)
    : GridWidget(parent), _halfEdge(halfEdge) {
  assert(_halfEdge != nullptr);
  _layout->addWidget(new QLabel("target:"), 0, 0, 1, 1);
  _layout->addWidget(WidgetTools::createPointerLineEdit(this, _halfEdge->getTarget()), 0, 1, 1, 1);
  qDebug() << "Create HalfEdgeWidget";
}

HalfEdgeWidget::~HalfEdgeWidget() {
  qDebug() << "Destroy HalfEdgeWidget";
}
