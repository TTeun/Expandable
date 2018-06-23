#ifndef INSPECTIONWIDGET_H
#define INSPECTIONWIDGET_H

#include <functional>

class QWidget;

template <typename Type, typename TypeWidget>
class InspectionWidget {
 public:
  static TypeWidget *createWidget(Type *pointerToObject, QWidget *parent) {
    return new TypeWidget(pointerToObject, parent);
  }

  static std::function<QWidget *()> createWidgetBuilder(Type *pointerToObject, QWidget *parent) {
    return std::bind(&TypeWidget::createWidget, pointerToObject, parent);
  }
};

#endif  // INSPECTIONWIDGET_H
