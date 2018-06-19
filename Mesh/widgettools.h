#ifndef MESHWIDGETTOOLS_H
#define MESHWIDGETTOOLS_H

#include <cstddef>

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
  static QDoubleSpinBox *createDoubleSpinBox(const double initialValue,
                                             QWidget *parent,
                                             const char *functionString);
  static QSpinBox *createConstantSpinBox(const size_t value, QWidget *parent);
  static QGridLayout *createInspectionWidgetLayout(QWidget *parent);
  static QLineEdit *createPointerLineEdit(void *ptr, QWidget *parent);
};

// auto *xSpinBox = new QDoubleSpinBox(this);
// xSpinBox->setValue(_vertex->_position.x());
// connect(xSpinBox, SIGNAL(valueChanged(double)), this, SLOT(setX(double)));

#endif  // MESHWIDGETTOOLS_H
