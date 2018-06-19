#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include "Mesh/mesh.h"
#include "Widgets/expandabletreewidget.h"

class CentralWidget : public QWidget {
  Q_OBJECT

 public:
  explicit CentralWidget(QWidget *parent = nullptr);

  ~CentralWidget();

 private:
  TreeWidget _treeWidget;
  Mesh _mesh;
};

#endif  // CENTRALWIDGET_H
