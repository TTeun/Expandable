#ifndef UPDATEDISPATCHER_H
#define UPDATEDISPATCHER_H

#include <QObject>

class Mesh;
class RenderObject;
class OpenGlWidget;

class UpdateDispatcher : public QObject {
  Q_OBJECT

 public:
  enum Update_Type { Redraw };

 private:
  UpdateDispatcher() = delete;

 public:
  static void setOpenGlWidget(OpenGlWidget *openGlWidget);

 public slots:
  static void receiveUpdate(Update_Type type);

 private:
  static OpenGlWidget *_openGlWidget;
};

#endif  // UPDATEDISPATCHER_H
