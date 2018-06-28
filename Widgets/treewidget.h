#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <initializer_list>
#include <vector>

class TreeWidget : public QWidget {
  Q_OBJECT

 public:
  TreeWidget(QWidget *parent);
  TreeWidget(const std::initializer_list<QWidget *> &widgets, QWidget *parent);

  void addWidget(QWidget *newWidget);
  void addWidgets(const std::initializer_list<QWidget *> &newWidgets);
  const std::vector<QWidget *> &widgets() const;

 private:
  void initLayout();
  std::vector<QWidget *> _widgets;
};

#endif  // TREEWIDGET_H
