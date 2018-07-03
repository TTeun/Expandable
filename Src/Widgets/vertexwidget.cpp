#include "vertexwidget.h"

#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QLabel>
#include <cassert>

#include "Mesh/vertex.h"
#include "Rendering/renderobject.h"
#include "updatedispatcher.h"
#include "widgettools.h"

#include <QDebug>

VertexWidget::VertexWidget(Vertex *vertex, QWidget *parent, RenderObject *renderObject)
    : GridWidget(parent), _vertex(vertex), _renderObject(renderObject) {
  assert(_vertex != nullptr);
  {
    auto *xDoubleSpinBox = WidgetTools::createDoubleSpinBox(this, vertex->getX());
    QObject::connect(xDoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(setX(double)));
    _layout->addWidget(xDoubleSpinBox, 0, 0, 1, 1);
  }
  {
    auto *yDoubleSpinBox = WidgetTools::createDoubleSpinBox(this, vertex->getY());
    QObject::connect(yDoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(setY(double)));
    _layout->addWidget(yDoubleSpinBox, 0, 1, 1, 1);
  }
  {
    auto *zDoubleSpinBox = WidgetTools::createDoubleSpinBox(this, vertex->getZ());
    QObject::connect(zDoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(setZ(double)));
    _layout->addWidget(zDoubleSpinBox, 0, 2, 1, 1);
  }
  QObject::connect(this, &VertexWidget::wasUpdated, UpdateDispatcher::receiveUpdate);
  _layout->setSpacing(0);
  qDebug() << "Create VertexWidget";
}

VertexWidget::~VertexWidget() {
  qDebug() << "Destroy VertexWidget";
}

void VertexWidget::setX(const double x) {
  _vertex->setX(x);
  _renderObject->needsUpdate(true);
  emit wasUpdated(UpdateDispatcher::Update_Type::Redraw);
}

void VertexWidget::setY(const double y) {
  _vertex->setY(y);
  _renderObject->needsUpdate(true);
  emit wasUpdated(UpdateDispatcher::Update_Type::Redraw);
}

void VertexWidget::setZ(const double z) {
  _vertex->setZ(z);
  _renderObject->needsUpdate(true);
  emit wasUpdated(UpdateDispatcher::Update_Type::Redraw);
}
