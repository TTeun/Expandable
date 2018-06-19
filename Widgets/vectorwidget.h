#ifndef VECTORWIDGET_H
#define VECTORWIDGET_H

#include <QDebug>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>
#include "inspectionwidget.h"
#include "widgettools.h"

template <typename Type, typename TypeWidget>
class VectorWidget : public QWidget,
                     public InspectionWidget<std::vector<Type>, VectorWidget<Type, TypeWidget>> {
 public:
  VectorWidget(std::vector<Type> *elements, QWidget *parent)
      : QWidget(parent), _elements(elements) {
    qDebug() << "Create vectorWidget";
    setObjectName("vectorWidget");
    auto *layout = new QVBoxLayout(this);
    layout->setAlignment(layout, Qt::AlignTop);
    layout->setContentsMargins(3, 3, 3, 3);
    layout->insertStretch(-1, 1);
    layout->setSpacing(4);
    layout->addWidget(new QLabel(QString("std::vector<") + Type::getName() + ">(" +
                                 QString::number(_elements->size()) + ")"));
    for (auto &element : *_elements) {
      auto *horizontalLayout = new QHBoxLayout();
      horizontalLayout->addWidget(WidgetTools::createIndexLabel(element.getIndex()));
      horizontalLayout->addWidget(TypeWidget::createWidget(&element, this));
      layout->addLayout(horizontalLayout);
    }
    setLayout(layout);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
  }

  ~VectorWidget() {
    qDebug() << "Destroy vectorWidget";
  }

 private:
  std::vector<Type> *_elements;
};

#endif  // VECTORWIDGET_H
