#ifndef MESHWIDGETTOOLS_H
#define MESHWIDGETTOOLS_H

#include <cstddef>
#include <limits>

class QLabel;
class QDoubleSpinBox;
class QSpinBox;
class QWidget;
class QGridLayout;
class QLineEdit;

class WidgetTools {
 public:
  WidgetTools() = delete;

  static QLabel *createIndexLabel(const size_t index);
  static QDoubleSpinBox *createDoubleSpinBox(QWidget *parent,
                                             const double initialValue,
                                             const double minimumValue = -100.,
                                             const double maximumValue = 100.,
                                             const double increment = 0.05);
  static QSpinBox *createConstantSpinBox(QWidget *parent, const size_t initialValue);
  static QGridLayout *createInspectionWidgetLayout(QWidget *parent);
  static QLineEdit *createPointerLineEdit(QWidget *parent, void *ptr);
};

// auto *xSpinBox = new QDoubleSpinBox(this);
// xSpinBox->setValue(_vertex->_position.x());
// connect(xSpinBox, SIGNAL(valueChanged(double)), this, SLOT(setX(double)));

#endif  // MESHWIDGETTOOLS_H
