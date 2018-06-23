#include "updatedispatcher.h"

#include "../Rendering/renderobject.h"
#include "../Widgets/openglwidget.h"

#include <QDebug>

std::unordered_map<const Mesh *, RenderObject *> UpdateDispatcher::_objectToRenderObjectMap;
OpenGlWidget *UpdateDispatcher::_openGlWidget = nullptr;

void UpdateDispatcher::addConnection(const Mesh *mesh, RenderObject *renderObject) {
  _objectToRenderObjectMap[mesh] = renderObject;
}

void UpdateDispatcher::setOpenGlWidget(OpenGlWidget *openGlWidget) {
  _openGlWidget = openGlWidget;
}

void UpdateDispatcher::receiveUpdate(const Mesh *ptr) {
  if (_objectToRenderObjectMap.find(ptr) == _objectToRenderObjectMap.end()) {
    qDebug() << "Mesh " << ptr << " not in map";
    return;
  }
  _objectToRenderObjectMap[ptr]->needsUpdate(true);
  qDebug() << "Mesh(" << ptr << ") was updated";
  if (_openGlWidget == nullptr) {
    qDebug() << "OpenGlWidget not linked to UpdateDispatcher";
    return;
  }
  _openGlWidget->update();
}
