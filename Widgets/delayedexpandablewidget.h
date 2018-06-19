#ifndef DELAYEDEXPANDABLEWIDGET_H
#define DELAYEDEXPANDABLEWIDGET_H

#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>
#include <cassert>
#include <functional>
#include "layoutfactory.h"

class DelayedExpandableWidget : public QWidget {
  Q_OBJECT
 public:
  typedef std::function<QWidget *()> WidgetBuilder;

  DelayedExpandableWidget(WidgetBuilder widgetBuilder, const QString &name, QWidget *parent);

 protected:
  virtual void create();

 protected slots:
  virtual void toggleWidgetVisibility();

 private:
  QPushButton *_qPushButton;
  const std::function<QWidget *()> _widgetBuilder;
  QWidget *_widget = nullptr;
};

#endif  // DELAYEDEXPANDABLEWIDGET_H
