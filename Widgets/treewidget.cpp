#include "treewidget.h"

#include <QVBoxLayout>
#include <algorithm>
#include "expandablewidget.h"
#include "layoutfactory.h"

TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent) {
  initLayout();
}

TreeWidget::TreeWidget(const std::initializer_list<QWidget *> &widgets, QWidget *parent)
    : QWidget(parent), _widgets(widgets) {
  initLayout();
  for (auto widgetIt = _widgets.begin(); widgetIt != _widgets.end(); ++widgetIt) {
    layout()->addWidget(*widgetIt);
  }
}

void TreeWidget::addWidget(QWidget *newWidget) {
  newWidget->setParent(this);
  _widgets.push_back(newWidget);
  layout()->addWidget(newWidget);
}

void TreeWidget::addWidgets(const std::initializer_list<QWidget *> &newWidgets) {
  std::for_each(newWidgets.begin(), newWidgets.end(), [this](QWidget *newWidget) {
    this->addWidget(newWidget);
  });
}

void TreeWidget::initLayout() {
  auto *layout = LayoutFactory::createLayout<QVBoxLayout>(this);
  setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
  setLayout(layout);
}

const std::vector<QWidget *> &TreeWidget::widgets() const {
  return _widgets;
}
