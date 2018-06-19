#ifndef EXPANDABLEWIDGET_H
#define EXPANDABLEWIDGET_H

#include <QPushButton>
#include <QWidget>

class ExpandableWidget : public QWidget {
  Q_OBJECT
 public:
  ExpandableWidget(QWidget *widget, const QString &name, QWidget *parent);

  QWidget *getWidget();

 protected slots:
  virtual void toggleWidgetVisibility();

 protected:
  QPushButton *_qPushButton;
  QWidget *_widget = nullptr;
};

#endif  // EXPANDABLEWIDGET_H
