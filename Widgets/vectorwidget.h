#ifndef VECTORWIDGET_H
#define VECTORWIDGET_H

#include "inspectionwidget.h"
#include "vectorfullcontentswidgetfactory.h"
#include "widgettools.h"

#include <QDebug>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include <vector>

class RenderObject;

template <typename Type, typename TypeWidget>
class VectorWidget : public QWidget,
                     public InspectionWidget<std::vector<Type>, VectorWidget<Type, TypeWidget>> {
 public:
  VectorWidget(std::vector<Type> *elements, QWidget *parent, RenderObject *renderObject)
      : QWidget(parent), _elements(elements), _renderObject(renderObject) {
    qDebug() << "Create vectorWidget";
    setObjectName("vectorWidget");
    auto *layout = new QVBoxLayout(this);
    layout->setAlignment(layout, Qt::AlignTop);
    layout->setContentsMargins(3, 3, 3, 3);
    layout->insertStretch(-1, 1);
    layout->setSpacing(4);
    layout->addWidget(new QLabel(QString("std::vector<") + Type::getName() + ">(" +
                                 QString::number(_elements->size()) + ")"));

    layout->addWidget(VectorFullContentsWidgetFactory::createWidget<Type, TypeWidget>(
        elements, this, _renderObject));

    setLayout(layout);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
  }

  ~VectorWidget() {
    qDebug() << "Destroy vectorWidget";
  }

 private:
  std::vector<Type> *_elements;
  RenderObject *_renderObject;
};

#endif  // VECTORWIDGET_H
