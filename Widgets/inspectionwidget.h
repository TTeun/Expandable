#ifndef INSPECTIONWIDGET_H
#define INSPECTIONWIDGET_H

#include <functional>

class QWidget;
class RenderObject;

template <typename Type, typename TypeWidget>
class InspectionWidget {
 public:
  static TypeWidget *createWidget(Type *pointerToObject,
                                  QWidget *parent,
                                  RenderObject *renderObject) {
    return new TypeWidget(pointerToObject, parent, renderObject);
  }

  static std::function<QWidget *()> createWidgetBuilder(Type *pointerToObject,
                                                        QWidget *parent,
                                                        RenderObject *renderObject) {
    return std::bind(&TypeWidget::createWidget, pointerToObject, parent, renderObject);
  }
};

#endif  // INSPECTIONWIDGET_H
