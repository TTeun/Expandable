#include "centralwidget.h"

#include "Mesh/vertex.h"
#include "Rendering/meshrenderobject.h"
#include "Widgets/delayedexpandablewidget.h"
#include "Widgets/directexpandablewidget.h"
#include "Widgets/meshviewwidget.h"
#include "Widgets/meshwidget.h"
#include "Widgets/openglwidget.h"
#include "Widgets/treewidget.h"
#include "Widgets/updatedispatcher.h"
#include "Widgets/vertexwidget.h"
#include "Widgets/viewwidget.h"
#include "layoutfactory.h"

#include <QDebug>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPalette>
#include <QSpinBox>
#include <QVBoxLayout>

CentralWidget::CentralWidget(QWidget* parent)
    : QWidget(parent),
      _treeWidget(new TreeWidget(this)),
      _openGlWidget(new OpenGlWidget(this)),
      _viewWidget(new ViewWidget(_openGlWidget.get(), this)) {
  setObjectName("centralWidget");
  auto* layout = createLayout();
  layout->addWidget(createGroupBox());
  buildOpenGlWidget();
  layout->addWidget(_openGlWidget.get());
  UpdateDispatcher::setOpenGlWidget(_openGlWidget.get());
  setLayout(layout);
  raise();
}

CentralWidget::~CentralWidget() {
}

QGroupBox* CentralWidget::createGroupBox() {
  auto* groupBox = new QGroupBox("GoPhEr");
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
  leftLayout->setSpacing(10);
  leftLayout->setContentsMargins(5, 10, 5, 10);
  buildTreeWidget();
  leftLayout->addWidget(_treeWidget.get());
  return groupBox;
}

QLayout* CentralWidget::createLayout() {
  auto* layout = new QHBoxLayout;
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);
  setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  return layout;
}

void CentralWidget::buildTreeWidget() {
  _treeWidget->addWidget(new DirectExpandableWidget(
      new DelayedExpandableWidget(MeshWidget::createWidgetBuilder(&_mesh, this), "Mesh", this),
      "Model",
      this));
  _treeWidget->addWidget(new DirectExpandableWidget(_viewWidget.get(), "View", this));
  _treeWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  for (auto& widgetIt : _treeWidget->widgets()) {
    widgetIt->layout()->setContentsMargins(0, 0, 0, 0);
  }
}

void CentralWidget::buildOpenGlWidget() {
  auto* meshRenderObject = new MeshRenderObject(&_mesh);

  _viewWidget->layout()->addWidget(new DirectExpandableWidget(
      new MeshViewWidget(meshRenderObject, _openGlWidget.get(), _viewWidget.get()),
      "Mesh view",
      this));
  UpdateDispatcher::addConnection(&_mesh, meshRenderObject);
  _openGlWidget->addRenderObject(meshRenderObject);
}
