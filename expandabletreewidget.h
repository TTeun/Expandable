#ifndef EXPANDABLETREEWIDGET_H
#define EXPANDABLETREEWIDGET_H

#include <QWidget>
#include <initializer_list>
#include <vector>

class ExpandableWidget;

class ExpandableTreeWidget : public QWidget {
  Q_OBJECT

 public:
  ExpandableTreeWidget(QWidget *parent);

  ExpandableTreeWidget(const std::initializer_list<ExpandableWidget *> &widgets, QWidget *parent);

  void addWidget(ExpandableWidget *newWidget);

  void addWidgets(const std::initializer_list<ExpandableWidget *> &newWidgets);

  const std::vector<ExpandableWidget *> &widgets() const;

 private:
  void initLayout();

  std::vector<ExpandableWidget *> _widgets;
};

#endif  // EXPANDABLETREEWIDGET_H
