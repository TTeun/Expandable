#include "expandablewidget.h"

#include <QPushButton>
#include <QVBoxLayout>

#include "layoutfactory.h"

ExpandableWidget::ExpandableWidget(const QString &name, QWidget *parent)
    : QWidget(parent), _qPushButton(new QPushButton(QString(" + ") + name, this)) {
  _qPushButton->setFixedHeight(21);
  _qPushButton->setFocusPolicy(Qt::NoFocus);
  _qPushButton->setContentsMargins(0, 0, 0, 0);
  {
    auto *layout = LayoutFactory::createLayout<QVBoxLayout>(this);
    layout->setContentsMargins(15, 0, 0, 0);
    layout->addWidget(_qPushButton);
    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);
  }
  setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}
