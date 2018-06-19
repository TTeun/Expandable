#include "centralwidget.h"

#include <QDebug>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPalette>
#include <QSpinBox>
#include <QVBoxLayout>
#include "Mesh/meshwidget.h"
#include "expandablewidget.h"
#include "layoutfactory.h"

#include "Mesh/vertex.h"
#include "Mesh/vertexwidget.h"
#include "delayedinspectionwidget.h"

CentralWidget::CentralWidget(QWidget* parent) : QWidget(parent), _treeWidget(this) {
  setObjectName("centralWidget");
  QGroupBox* groupBox = new QGroupBox("GoPhEr", this);
  QVBoxLayout* leftLayout = LayoutFactory::createLayout<QVBoxLayout>(this);
  leftLayout->setAlignment(Qt::AlignTop);
  groupBox->setLayout(leftLayout);
  {
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::gray);
    groupBox->setAutoFillBackground(true);
    groupBox->setPalette(pal);
  }
  groupBox->setMinimumSize(300, 0);
  leftLayout->addWidget(&_treeWidget);
  leftLayout->setSpacing(10);
  leftLayout->setContentsMargins(5, 10, 5, 10);
  leftLayout->insertStretch(-1, 1);
  auto* layout = LayoutFactory::createLayout<QHBoxLayout>(this);
  layout->addWidget(groupBox);
  layout->insertStretch(-1, 1);
  setLayout(layout);
  _treeWidget.addWidget(new ExpandableWidget(
      new DelayedInspectionWidget(MeshWidget::createWidgetBuilder(&_mesh, this), "Mesh", this),
      "Model",
      this));

  raise();
  setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  _treeWidget.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  for (auto& widgetIt : _treeWidget.widgets()) {
    widgetIt->layout()->setContentsMargins(0, 0, 0, 0);
  }
}

CentralWidget::~CentralWidget() {
}
