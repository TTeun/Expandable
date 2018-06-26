#include "facewidget.h"

#include "../Mesh/face.h"
#include "../Mesh/mesh.h"
#include "updatedispatcher.h"
#include "widgettools.h"

#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <cassert>

FaceWidget::FaceWidget(Face *face, QWidget *parent, Mesh *parentObject)
    : GridWidget(parent), _face(face), _parentObject(parentObject) {
  assert(_face != nullptr);
  _layout->addWidget(new QLabel("val:"), 0, 0, 1, 1);
  _layout->addWidget(WidgetTools::createConstantSpinBox(this, _face->getVal()), 0, 1, 1, 1);
  //  QObject::connect(this, &FaceWidget::wasUpdated, UpdateDispatcher::receiveUpdate);

  qDebug() << "Create FaceWidget";
}

FaceWidget::~FaceWidget() {
  qDebug() << "Destroy FaceWidget";
}
