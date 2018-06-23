#ifndef FACEWIDGET_H
#define FACEWIDGET_H

#include <functional>
#include "gridwidget.h"
#include "inspectionwidgetwithparent.h"

class Face;
class Mesh;

class FaceWidget : public GridWidget, public InspectionWidgetWithParent<Face, FaceWidget, Mesh> {
  Q_OBJECT
 public:
  FaceWidget(Face *face, QWidget *parent, Mesh *parentObject);

 public:
  ~FaceWidget();

 signals:
  void wasUpdated(const Mesh *ptr);

 private:
  Face *_face;
  Mesh *_parentObject = nullptr;
};

#endif  // FACEWIDGET_H
