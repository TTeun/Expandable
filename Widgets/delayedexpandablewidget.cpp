#include "delayedexpandablewidget.h"

#include <functional>

DelayedExpandableWidget::DelayedExpandableWidget(WidgetBuilder widgetBuilder,
                                                 const QString &name,
                                                 QWidget *parent)
    : QWidget(parent),
      _qPushButton(new QPushButton(QString("+ ") + name, this)),
      _widgetBuilder(std::move(widgetBuilder)) {
  _qPushButton->setFixedHeight(21);
  _qPushButton->setFocusPolicy(Qt::NoFocus);
  _qPushButton->setContentsMargins(0, 0, 0, 0);
  auto *layout = LayoutFactory::createLayout<QVBoxLayout>(this);
  layout->setContentsMargins(15, 0, 0, 0);
  layout->addWidget(_qPushButton);
  setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  layout->setAlignment(Qt::AlignTop);
  setLayout(layout);
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
  text.replace(0, 1, wasVisible ? "-" : "+");
  _qPushButton->setText(text);
}

void DelayedExpandableWidget::create() {
  _widget = _widgetBuilder();
  layout()->addWidget(_widget);
}
