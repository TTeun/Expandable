#ifndef DELAYEDEXPANDABLEWIDGET_H
#define DELAYEDEXPANDABLEWIDGET_H

#include "expandablewidget.h"

#include <functional>

class QString;
class QPushButton;

class DelayedExpandableWidget : public ExpandableWidget {
  Q_OBJECT
 public:
  typedef std::function<QWidget *()> WidgetBuilder;

  DelayedExpandableWidget(WidgetBuilder widgetBuilder, const QString &name, QWidget *parent);

 protected:
  virtual void create();

 protected slots:
  virtual void toggleWidgetVisibility();

 private:
  const WidgetBuilder _widgetBuilder;
};

#endif  // DELAYEDEXPANDABLEWIDGET_H
