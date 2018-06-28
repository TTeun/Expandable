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
  static QDoubleSpinBox *createDoubleSpinBox(QWidget *parent,
                                             const double initialValue,
                                             const double minimumValue = -5.,
                                             const double maximumValue = 5.,
                                             const double increment = 0.05);
  static QSpinBox *createConstantSpinBox(QWidget *parent, const size_t initialValue);
  static QGridLayout *createInspectionWidgetLayout(QWidget *parent);
  static QLineEdit *createPointerLineEdit(QWidget *parent, void *ptr);
};

#endif  // MESHWIDGETTOOLS_H
