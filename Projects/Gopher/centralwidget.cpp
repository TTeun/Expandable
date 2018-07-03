#include "centralwidget.h"

#include "Mesh/mesh.h"
#include "Mesh/meshfactory.h"
#include "Rendering/bsplinerenderer.h"
#include "Rendering/meshinterpolationsurface.h"
#include "Rendering/meshinterpolator.h"
#include "Rendering/meshrenderobject.h"
#include "Widgets/delayedexpandablewidget.h"
#include "Widgets/directexpandablewidget.h"
#include "Widgets/meshviewwidget.h"
#include "Widgets/meshwidget.h"
#include "Widgets/openglwidget.h"
#include "Widgets/treewidget.h"
#include "Widgets/updatedispatcher.h"
#include "Widgets/viewwidget.h"
#include "layoutfactory.h"

#include <QDebug>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPalette>
#include <QSlider>
#include <QVBoxLayout>

CentralWidget::CentralWidget(QWidget* parent)
    : QWidget(parent),
      _treeWidget(std::make_unique<TreeWidget>(this)),
      _openGlWidget(std::make_unique<OpenGlWidget>(this)),
      _viewWidget(std::make_unique<ViewWidget>(_openGlWidget.get(), this)),

      _mesh(std::move(MeshFactory::buildNGon(8))),
      _mesh2(std::move(MeshFactory::buildTwoSquares())),
      _mesh3(std::move(MeshFactory::buildTwoSquares_Moved())),

      _meshRenderObject(new MeshRenderObject(_mesh.get(), RenderObject::Top_Left)),
      _meshRenderObject2(new MeshRenderObject(_mesh2.get(), RenderObject::Bottom_Left)),
      _meshRenderObject3(new MeshRenderObject(_mesh3.get(), RenderObject::Bottom_Left)),

      _bSplineRenderer(new BSplineRenderer(_mesh.get(), RenderObject::Top_Left)),
      _bSplineRenderer2(new BSplineRenderer(_mesh2.get(), RenderObject::Bottom_Left)),
      _bSplineRenderer3(new BSplineRenderer(_mesh3.get(), RenderObject::Bottom_Left)),

      _meshInterpolator(new MeshInterpolator(_mesh.get(), _mesh2.get(), RenderObject::Top_Right)),
      _meshInterpolationSurface(
          new MeshInterpolationSurface(_mesh.get(), _mesh2.get(), RenderObject::Right)) {
  setObjectName("centralWidget");

  _meshRenderObject->setTransform(-0.5, -0.56, 0.33);
  _bSplineRenderer->setTransform(-0.5, -0.56, 0.33);
  _meshRenderObject2->setTransform(-0.5, -0.0, 0.33);
  _bSplineRenderer2->setTransform(-0.5, -0.0, 0.33);
  _meshRenderObject3->setTransform(-0.5, 0.46, 0.33);
  _bSplineRenderer3->setTransform(-0.5, 0.46, 0.33);
  _meshInterpolationSurface->setTransform(0.4, 0, 0.5);

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
          {MeshWidget::createWidget(_mesh.get(), this, _meshRenderObject),
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
          {MeshWidget::createWidget(_mesh2.get(), this, _meshRenderObject2),
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
  _openGlWidget->addRenderObject(_meshRenderObject3);
  _openGlWidget->addRenderObject(_bSplineRenderer3);
  //  _openGlWidget->addRenderObject(_meshInterpolator);
  _openGlWidget->addRenderObject(_meshInterpolationSurface);
}
