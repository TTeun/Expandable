#include "updatedispatcher.h"

#include "../Widgets/openglwidget.h"

OpenGlWidget *UpdateDispatcher::_openGlWidget = nullptr;

void UpdateDispatcher::setOpenGlWidget(OpenGlWidget *openGlWidget) {
  _openGlWidget = openGlWidget;
}

void UpdateDispatcher::receiveUpdate(UpdateDispatcher::Update_Type type) {
  switch (type) {
    case Update_Type::Redraw:
      _openGlWidget->update();
      break;
    default:
      break;
  }
}
