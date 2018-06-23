#ifndef VECTORFULLCONTENTSWIDGETFACTORY_H
#define VECTORFULLCONTENTSWIDGETFACTORY_H

#include "widgettools.h"

#include <QGridLayout>
#include <QWidget>

#include <vector>

class VectorFullContentsWidgetFactory : public QWidget {
 public:
  template <typename Type, typename TypeWidget, typename ParentObject>
  static QWidget *createWidget(std::vector<Type> *elements,
                               QWidget *parent,
                               ParentObject *parentObject) {
    QWidget *widget = new QWidget(parent);
    size_t row = 0u;
    auto *layout = new QGridLayout();
    for (auto &element : *elements) {
      layout->addWidget(WidgetTools::createIndexLabel(element.getIndex()), row, 0, 1, 1);
      layout->addWidget(TypeWidget::createWidget(&element, widget, parentObject), row, 1, 1, 1);
      ++row;
    }
    widget->setLayout(layout);
    return widget;
  }
};

#endif  // VECTORFULLCONTENTSWIDGETFACTORY_H
