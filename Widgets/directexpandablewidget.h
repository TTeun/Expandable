#ifndef DIRECTEXPANDABLEWIDGET_H
#define DIRECTEXPANDABLEWIDGET_H

#include "expandablewidget.h"

class DirectExpandableWidget : public ExpandableWidget {
  Q_OBJECT
 public:
  DirectExpandableWidget(QWidget *widget, const QString &name, QWidget *parent);

  DirectExpandableWidget(std::vector<QWidget *> widgets, const QString &name, QWidget *parent);

 protected slots:
  virtual void toggleWidgetVisibility();
};

#endif  // DIRECTEXPANDABLEWIDGET_H
