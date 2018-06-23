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
}

void DelayedExpandableWidget::toggleWidgetVisibility() {
  bool wasVisible = _widget != nullptr;
  if (not wasVisible) {
    create();
    assert(_widget != nullptr);
  } else {
    delete _widget;
    _widget = nullptr;
  }
  auto text = _qPushButton->text();
  text.replace(0, 2, wasVisible ? " +" : " -");
  _qPushButton->setText(text);
}

void DelayedExpandableWidget::create() {
  _widget = _widgetBuilder();
  layout()->addWidget(_widget);
}
