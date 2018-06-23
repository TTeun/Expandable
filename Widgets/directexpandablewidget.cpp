#include "directexpandablewidget.h"

#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include "layoutfactory.h"

DirectExpandableWidget::DirectExpandableWidget(QWidget *widget,
                                               const QString &name,
                                               QWidget *parent)
    : ExpandableWidget(name, parent) {
  _widget = widget;
  layout()->addWidget(_widget);
  _widget->setParent(this);
  _widget->hide();
  QObject::connect(_qPushButton, SIGNAL(released()), SLOT(toggleWidgetVisibility()));
}

void DirectExpandableWidget::toggleWidgetVisibility() {
  _widget->setVisible(_widget->isHidden());
  auto text = _qPushButton->text();
  text.replace(0, 2, _widget->isHidden() ? " +" : " -");
  _qPushButton->setText(text);
}
