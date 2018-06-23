#include "centralwidget.h"

#include <QDebug>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPalette>
#include <QSpinBox>
#include <QVBoxLayout>
#include "Mesh/vertex.h"
#include "Widgets/delayedexpandablewidget.h"
#include "Widgets/directexpandablewidget.h"
#include "Widgets/meshwidget.h"
#include "Widgets/vertexwidget.h"
#include "layoutfactory.h"

CentralWidget::CentralWidget(QWidget* parent)
    : QWidget(parent), _treeWidget(new TreeWidget(this)), _openGlWidget(new OpenGlWidget(this)) {
  setObjectName("centralWidget");
  QGroupBox* groupBox = new QGroupBox("GoPhEr");
  QVBoxLayout* leftLayout = LayoutFactory::createLayout<QVBoxLayout>(this);
  leftLayout->setAlignment(Qt::AlignTop);
  groupBox->setLayout(leftLayout);
  {
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::gray);
    groupBox->setAutoFillBackground(true);
    groupBox->setPalette(pal);
  }
  groupBox->setMinimumWidth(300);
  groupBox->setMaximumWidth(400);
  groupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
  groupBox->setFixedWidth(300);
  leftLayout->addWidget(_treeWidget);
  leftLayout->setSpacing(10);
  leftLayout->setContentsMargins(5, 10, 5, 10);
  auto* layout = new QHBoxLayout;
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);
  layout->addWidget(groupBox);
  //  layout->insertStretch(-1, 1);
  setLayout(layout);
  layout->addWidget(_openGlWidget);
  _treeWidget->addWidget(new DirectExpandableWidget(
      new DelayedExpandableWidget(MeshWidget::createWidgetBuilder(&_mesh, this), "Mesh", this),
      "Model",
      this));
  _treeWidget->addWidget(new DirectExpandableWidget(
      new DelayedExpandableWidget(MeshWidget::createWidgetBuilder(&_mesh, this), "Mesh", this),
      "Model",
      this));

  raise();
  setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  _treeWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  for (auto& widgetIt : _treeWidget->widgets()) {
    widgetIt->layout()->setContentsMargins(0, 0, 0, 0);
  }
}

CentralWidget::~CentralWidget() {
}
