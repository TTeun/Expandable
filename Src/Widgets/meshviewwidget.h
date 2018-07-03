#ifndef MESHVIEWWIDGET_H
#define MESHVIEWWIDGET_H

#include <QWidget>
#include "Rendering/renderobject.h"

class OpenGlWidget;
class QGridLayout;
class MeshRenderObject;
class RenderObject;

class MeshViewWidget : public QWidget {
  Q_OBJECT
 public:
  explicit MeshViewWidget(MeshRenderObject *meshRenderObject,
                          OpenGlWidget *openGlWidget,
                          QWidget *parent);

 signals:

 private slots:
  void toggleRenderMode(RenderObject::Render_Mode renderMode, bool value);

 private:
  void addCheckBox(RenderObject::Render_Mode renderMode, size_t pos);

  MeshRenderObject *_meshRenderObject;
  OpenGlWidget *_openGlWidget;
  QGridLayout *_layout;
};

#endif  // MESHVIEWWIDGET_H
