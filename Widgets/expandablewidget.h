#ifndef EXPANDABLEWIDGET_H
#define EXPANDABLEWIDGET_H

#include <QPushButton>
#include <QWidget>

class ExpandableWidget : public QWidget {
  Q_OBJECT
 public:
  ExpandableWidget(QWidget *viewable, const QString &name, QWidget *parent);

  QWidget *widget() const;

 private slots:
  virtual void toggleWidgetVisibility();

 private:
  QPushButton *_qPushButton;
  QWidget *_widget;
};

#endif  // EXPANDABLEWIDGET_H
