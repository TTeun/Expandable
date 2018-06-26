#include "delayedexpandablewidget.h"

#include "layoutfactory.h"

#include <QPushButton>
#include <QVBoxLayout>

#include <cassert>
#include <functional>

DelayedExpandableWidget::DelayedExpandableWidget(WidgetBuilder widgetBuilder,
                                                 const QString &name,
                                                 QWidget *parent)
    : ExpandableWidget(name, parent), _widgetBuilder(std::move(widgetBuilder)) {
  QObject::connect(_qPushButton, SIGNAL(released()), SLOT(toggleWidgetVisibility()));
  _widgets.push_back(nullptr);
}

void DelayedExpandableWidget::toggleWidgetVisibility() {
  bool wasVisible = _widgets[0] != nullptr;
  if (not wasVisible) {
    create();
    assert(_widgets[0] != nullptr);
  } else {
    delete _widgets[0];
    _widgets[0] = nullptr;
  }
  auto text = _qPushButton->text();
  text.replace(0, 2, wasVisible ? " +" : " -");
  _qPushButton->setText(text);
}

void DelayedExpandableWidget::create() {
  if (_widgets.size() == 0u)
    _widgets.push_back(nullptr);

  _widgets[0] = _widgetBuilder();
  layout()->addWidget(_widgets[0]);
}
