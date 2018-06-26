#ifndef EXPANDABLEWIDGET_H
#define EXPANDABLEWIDGET_H

#include <QWidget>

#include <cassert>
#include <vector>

class QPushButton;
class QString;

class ExpandableWidget : public QWidget {
  Q_OBJECT
 public:
  explicit ExpandableWidget(const QString &name, QWidget *parent);

  QWidget *getWidget(size_t index) {
    assert(index < _widgets.size());
    return _widgets[index];
  }

  const QWidget *getWidget(size_t index) const {
    assert(index < _widgets.size());
    return _widgets[index];
  }

 protected slots:
  virtual void toggleWidgetVisibility() = 0;

 protected:
  QPushButton *_qPushButton;
  std::vector<QWidget *> _widgets;
};

#endif  // EXPANDABLEWIDGET_H
