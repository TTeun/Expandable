#include "centralwidget.h"

#include "Mesh/vertex.h"
#include "Rendering/bsplinerenderer.h"
#include "Rendering/meshinterpolator.h"
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
#include <QSlider>
#include <QSpinBox>
#include <QVBoxLayout>

CentralWidget::CentralWidget(QWidget* parent)
    : QWidget(parent),
      _treeWidget(std::make_unique<TreeWidget>(this)),
      _openGlWidget(std::make_unique<OpenGlWidget>(this)),
      _viewWidget(std::make_unique<ViewWidget>(_openGlWidget.get(), this)),
      _meshRenderObject(new MeshRenderObject(&_mesh, 1)),
      _bSplineRenderer(new BSplineRenderer(&_mesh, 1)),
      _meshRenderObject2(new MeshRenderObject(&_mesh2, 2)),
      _bSplineRenderer2(new BSplineRenderer(&_mesh2, 2)),
      _meshInterpolator(new MeshInterpolator(&_mesh, &_mesh2, 3)) {
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

  auto slider = new QSlider;
  connect(slider, &QSlider::valueChanged, [this](int value) {
    MeshInterpolator::_alpha = (value / 50.);
    this->_openGlWidget->update();
  });
  leftLayout->addWidget(slider);
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
      new DirectExpandableWidget(
          {MeshWidget::createWidget(&_mesh, this, _meshRenderObject),
           new DirectExpandableWidget(
               new MeshViewWidget(_meshRenderObject, _openGlWidget.get(), _viewWidget.get()),
               "Mesh view",
               this)},
          "Mesh",
          this),
      "Model",
      this));

  _treeWidget->addWidget(new DirectExpandableWidget(
      new DirectExpandableWidget(
          {MeshWidget::createWidget(&_mesh2, this, _meshRenderObject2),
           new DirectExpandableWidget(
               new MeshViewWidget(_meshRenderObject2, _openGlWidget.get(), _viewWidget.get()),
               "Mesh view",
               this)},
          "Mesh",
          this),
      "Model",
      this));
  _treeWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  for (auto& widgetIt : _treeWidget->widgets()) {
    widgetIt->layout()->setContentsMargins(0, 0, 0, 0);
  }
}

void CentralWidget::buildOpenGlWidget() {
  _openGlWidget->addRenderObject(_meshRenderObject);
  _openGlWidget->addRenderObject(_bSplineRenderer);
  _openGlWidget->addRenderObject(_meshRenderObject2);
  _openGlWidget->addRenderObject(_bSplineRenderer2);
  _openGlWidget->addRenderObject(_meshInterpolator);
}
