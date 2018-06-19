#include "vertexwidget.h"

#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QLabel>
#include <cassert>
#include <functional>
#include "vertex.h"
#include "widgettools.h"

#include <QDebug>

VertexWidget::VertexWidget(Vertex *vertex, QWidget *parent) : GridWidget(parent), _vertex(vertex) {
  assert(_vertex != nullptr);
  _layout->addWidget(new QLabel("x:"), 0, 0, 1, 1);
  _layout->addWidget(
      WidgetTools::createDoubleSpinBox(vertex->getX(), this, SLOT(setX(double))), 0, 1, 1, 1);
  _layout->addWidget(new QLabel("y:"), 0, 2, 1, 1);
  _layout->addWidget(
      WidgetTools::createDoubleSpinBox(vertex->getY(), this, SLOT(setY(double))), 0, 3, 1, 1);
  qDebug() << "Create VertexWidget";
}

VertexWidget::~VertexWidget() {
  qDebug() << "Destroy VertexWidget";
}

void VertexWidget::setX(const double x) {
  _vertex->setX(x);
}

void VertexWidget::setY(const double y) {
  _vertex->setY(y);
}
