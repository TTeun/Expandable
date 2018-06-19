#include "expandablewidget.h"

#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include "layoutfactory.h"

ExpandableWidget::ExpandableWidget(QWidget *viewable, const QString &name, QWidget *parent)
    : QWidget(parent),
      _qPushButton(new QPushButton(QString("+ ") + name, this)),
      _widget(viewable) {
  _qPushButton->setFixedHeight(21);
  _qPushButton->setFocusPolicy(Qt::NoFocus);
  _qPushButton->setContentsMargins(0, 0, 0, 0);
  {
    auto *layout = LayoutFactory::createLayout<QVBoxLayout>(this);
    layout->setContentsMargins(15, 0, 0, 0);
    layout->addWidget(_qPushButton);
    layout->addWidget(_widget);
    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);
  }
  _widget->setParent(this);
  _widget->hide();
  QObject::connect(_qPushButton, SIGNAL(released()), SLOT(toggleWidgetVisibility()));
  setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
}

void ExpandableWidget::toggleWidgetVisibility() {
  _widget->setVisible(_widget->isHidden());
  auto text = _qPushButton->text();
  text.replace(0, 1, _widget->isHidden() ? "+" : "-");
  _qPushButton->setText(text);
}

QWidget *ExpandableWidget::widget() const {
  return _widget;
}
