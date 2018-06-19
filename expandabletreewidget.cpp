#include "expandabletreewidget.h"

#include <QVBoxLayout>
#include <algorithm>
#include "expandablewidget.h"
#include "layoutfactory.h"

ExpandableTreeWidget::ExpandableTreeWidget(QWidget *parent) : QWidget(parent) {
  initLayout();
}

ExpandableTreeWidget::ExpandableTreeWidget(const std::initializer_list<ExpandableWidget *> &widgets,
                                           QWidget *parent)
    : QWidget(parent), _widgets(widgets) {
  initLayout();
  for (auto widgetIt = _widgets.begin(); widgetIt != _widgets.end(); ++widgetIt) {
    layout()->addWidget(*widgetIt);
  }
}

void ExpandableTreeWidget::addWidget(ExpandableWidget *newWidget) {
  newWidget->setParent(this);
  newWidget->widget()->setParent(newWidget);
  _widgets.push_back(newWidget);
  layout()->addWidget(newWidget);
}

void ExpandableTreeWidget::addWidgets(const std::initializer_list<ExpandableWidget *> &newWidgets) {
  std::for_each(newWidgets.begin(), newWidgets.end(), [this](ExpandableWidget *newWidget) {
    this->addWidget(newWidget);
  });
}

void ExpandableTreeWidget::initLayout() {
  auto *layout = LayoutFactory::createLayout<QVBoxLayout>(this);
  setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
  setLayout(layout);
}

const std::vector<ExpandableWidget *> &ExpandableTreeWidget::widgets() const {
  return _widgets;
}
