#include "halfedgewidget.h"

#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <cassert>
#include "face.h"
#include "halfedge.h"
#include "widgettools.h"

HalfEdgeWidget::HalfEdgeWidget(HalfEdge *halfEdge, QWidget *parent)
    : GridWidget(parent), _halfEdge(halfEdge) {
  assert(_halfEdge != nullptr);
  _layout->addWidget(new QLabel("target:"), 0, 0, 1, 1);
  _layout->addWidget(WidgetTools::createPointerLineEdit(_halfEdge->getTarget(), this), 0, 1, 1, 1);
  qDebug() << "Create HalfEdgeWidget";
}

HalfEdgeWidget::~HalfEdgeWidget() {
  qDebug() << "Destroy HalfEdgeWidget";
}
