#ifndef INSPECTIONWIDGETWITHPARENT_H
#define INSPECTIONWIDGETWITHPARENT_H

#include <functional>

class QWidget;

template <typename Type, typename TypeWidget, typename ParentObject>
class InspectionWidgetWithParent {
 public:
  static TypeWidget *createWidget(Type *pointerToObject,
                                  QWidget *parent,
                                  ParentObject *parentObject) {
    return new TypeWidget(pointerToObject, parent, parentObject);
  }

  static std::function<QWidget *()> createWidgetBuilder(Type *pointerToObject,
                                                        QWidget *parent,
                                                        ParentObject *parentObject) {
    return std::bind(&TypeWidget::createWidget, pointerToObject, parent, parentObject);
  }
};

#endif  // INSPECTIONWIDGETWITHPARENT_H
