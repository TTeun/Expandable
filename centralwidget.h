#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>

#include <memory>

#include "Mesh/mesh.h"

class TreeWidget;
class OpenGlWidget;
class QGroupBox;
class QLayout;
class ViewWidget;

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
  Mesh _mesh;
};

#endif  // CENTRALWIDGET_H
