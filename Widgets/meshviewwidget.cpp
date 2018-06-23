#include "meshviewwidget.h"

#include "../Rendering/meshrenderobject.h"
#include "openglwidget.h"

#include <QCheckBox>
#include <QDebug>
#include <QGridLayout>

#include <functional>

MeshViewWidget::MeshViewWidget(MeshRenderObject *meshRenderObject,
                               OpenGlWidget *openGlWidget,
                               QWidget *parent)
    : QWidget(parent), _meshRenderObject(meshRenderObject), _openGlWidget(openGlWidget) {
  _layout = new QGridLayout;
  _layout->setContentsMargins(0, 0, 0, 0);
  _layout->setSpacing(0);
  size_t pos = 0;
  for (size_t i = 1u; i != RenderObject::Render_Mode::End; i <<= 1u) {
    if (i & MeshRenderObject::getAvailableRenderModes()) {
      addCheckBox(static_cast<RenderObject::Render_Mode>(i), pos);
      ++pos;
    }
  }
  setLayout(_layout);
}

void MeshViewWidget::toggleRenderMode(RenderObject::Render_Mode renderMode, bool value) {
  _meshRenderObject->toggleRenderMode(renderMode, value);
  _openGlWidget->update();
}

void MeshViewWidget::addCheckBox(RenderObject::Render_Mode renderMode, size_t pos) {
  auto *checkBox = new QCheckBox(RenderObject::getNameOfRenderMode(renderMode));
  checkBox->setChecked(true);
  connect(checkBox, &QCheckBox::toggled, [this, renderMode](bool value) {
    this->toggleRenderMode(renderMode, value);
  });
  _layout->addWidget(checkBox, 0, pos, 1, 1);
}
