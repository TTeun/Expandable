#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <initializer_list>
#include <vector>

class ExpandableWidget;

class TreeWidget : public QWidget {
  Q_OBJECT

 public:
  TreeWidget(QWidget *parent);

  TreeWidget(const std::initializer_list<ExpandableWidget *> &widgets, QWidget *parent);

  void addWidget(ExpandableWidget *newWidget);

  void addWidgets(const std::initializer_list<ExpandableWidget *> &newWidgets);

  const std::vector<ExpandableWidget *> &widgets() const;

 private:
  void initLayout();

  std::vector<ExpandableWidget *> _widgets;
};

#endif  // TREEWIDGET_H
