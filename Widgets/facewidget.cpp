#include "facewidget.h"

#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <cassert>
#include "../Mesh/face.h"
#include "widgettools.h"

// FaceWidget::FaceWidget(Face *face, QWidget *parent) : InspectionWidget(parent), _face(face) {
//  assert(_face != nullptr);
//  _layout->addWidget(new QLabel("val:"), 0, 0, 1, 1);
//  _layout->addWidget(WidgetTools::createConstantSpinBox(_face->getVal(), this), 0, 1, 1, 1);
//}
