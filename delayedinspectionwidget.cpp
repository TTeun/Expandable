#include "delayedinspectionwidget.h"

#include <functional>

DelayedInspectionWidget::DelayedInspectionWidget(WidgetBuilder widgetBuilder,
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
  setLayout(layout);
  QObject::connect(_qPushButton, SIGNAL(released()), SLOT(toggleWidgetVisibility()));
}

void DelayedInspectionWidget::toggleWidgetVisibility() {
  bool wasVisible = _containedWidget != nullptr;
  if (not wasVisible) {
    create();
    assert(_containedWidget != nullptr);
  } else {
    delete _containedWidget;
    _containedWidget = nullptr;
  }
  auto text = _qPushButton->text();
  text.replace(0, 1, wasVisible ? "-" : "+");
  _qPushButton->setText(text);
}

void DelayedInspectionWidget::create() {
  _containedWidget = _widgetBuilder();
  layout()->addWidget(_containedWidget);
  layout()->setAlignment(Qt::AlignTop);
}
