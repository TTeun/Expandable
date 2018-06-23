#ifndef UPDATEDISPATCHER_H
#define UPDATEDISPATCHER_H

#include <QObject>
#include <unordered_map>

class Mesh;
class RenderObject;
class OpenGlWidget;

class UpdateDispatcher : public QObject {
  Q_OBJECT

  UpdateDispatcher() = delete;

 public:
  static void addConnection(const Mesh *mesh, RenderObject *renderObject);
  static void setOpenGlWidget(OpenGlWidget *openGlWidget);

 public slots:
  static void receiveUpdate(const Mesh *ptr);

 private:
  static std::unordered_map<const Mesh *, RenderObject *> _objectToRenderObjectMap;
  static OpenGlWidget *_openGlWidget;
};

#endif  // UPDATEDISPATCHER_H
