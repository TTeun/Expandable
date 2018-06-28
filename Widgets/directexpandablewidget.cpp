#include "directexpandablewidget.h"

#include <QPushButton>
#include <QString>
#include <QVBoxLayout>

DirectExpandableWidget::DirectExpandableWidget(QWidget *widget,
                                               const QString &name,
                                               QWidget *parent)
    : ExpandableWidget(name, parent) {
  _widgets.push_back(widget);
  layout()->addWidget(_widgets[0]);
  _widgets[0]->setParent(this);
  _widgets[0]->hide();
  QObject::connect(_qPushButton, SIGNAL(released()), SLOT(toggleWidgetVisibility()));
}

DirectExpandableWidget::DirectExpandableWidget(std::vector<QWidget *> widgets,
                                               const QString &name,
                                               QWidget *parent)
    : ExpandableWidget(name, parent) {
  for (auto *widget : widgets) {
    _widgets.push_back(widget);
    layout()->addWidget(widget);
    widget->setParent(this);
    widget->hide();
  }
  QObject::connect(_qPushButton, SIGNAL(released()), SLOT(toggleWidgetVisibility()));
}

void DirectExpandableWidget::toggleWidgetVisibility() {
  for (auto *widget : _widgets) {
    widget->setVisible(widget->isHidden());
  }
  auto text = _qPushButton->text();
  text.replace(0, 2, _widgets[0]->isHidden() ? " +" : " -");
  _qPushButton->setText(text);
}
