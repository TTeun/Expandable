#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>

#include <memory>

class TreeWidget;
class OpenGlWidget;
class QGroupBox;
class QLayout;
class ViewWidget;
class MeshRenderObject;
class BSplineRenderer;
class MeshInterpolator;
class MeshInterpolationSurface;
class Mesh;

class CentralWidget : public QWidget {
  Q_OBJECT

 public:
  explicit CentralWidget(QWidget *parent = nullptr);

  ~CentralWidget();

 private:
  QGroupBox *createGroupBox();
  QLayout *createLayout();
  void buildTreeWidget();
  void buildOpenGlWidget();

  std::unique_ptr<TreeWidget> _treeWidget;
  std::unique_ptr<OpenGlWidget> _openGlWidget;
  std::unique_ptr<ViewWidget> _viewWidget;

  std::unique_ptr<Mesh> _mesh;
  std::unique_ptr<Mesh> _mesh2;
  std::unique_ptr<Mesh> _mesh3;

  MeshRenderObject *_meshRenderObject;
  MeshRenderObject *_meshRenderObject2;
  MeshRenderObject *_meshRenderObject3;

  BSplineRenderer *_bSplineRenderer;
  BSplineRenderer *_bSplineRenderer2;
  BSplineRenderer *_bSplineRenderer3;

  MeshInterpolator *_meshInterpolator;
  MeshInterpolationSurface *_meshInterpolationSurface;
};

#endif  // CENTRALWIDGET_H
