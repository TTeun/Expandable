#ifndef EXPANDABLEWIDGET_H
#define EXPANDABLEWIDGET_H

#include <QWidget>

class QPushButton;
class QString;

class ExpandableWidget : public QWidget {
  Q_OBJECT
 public:
  explicit ExpandableWidget(const QString &name, QWidget *parent);

  QWidget *getWidget() {
    return _widget;
  }

  const QWidget *getWidget() const {
    return _widget;
  }

 protected slots:
  virtual void toggleWidgetVisibility() = 0;

 protected:
  QPushButton *_qPushButton;
  QWidget *_widget = nullptr;
};

#endif  // EXPANDABLEWIDGET_H
