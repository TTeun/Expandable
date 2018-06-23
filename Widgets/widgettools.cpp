#include "widgettools.h"

#include <QDoubleSpinBox>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QObject>
#include <QSpinBox>
#include <QString>
#include <sstream>
#include <string>

QLabel *WidgetTools::createIndexLabel(const size_t index) {
  return new QLabel("# " + QString::number(index) + ":  ");
}

QDoubleSpinBox *WidgetTools::createDoubleSpinBox(QWidget *parent,
                                                 const char *functionString,
                                                 const double initialValue,
                                                 const double minimumValue,
                                                 const double maximumValue) {
  auto *doubleSpinBox = new QDoubleSpinBox(parent);
  doubleSpinBox->setValue(initialValue);
  doubleSpinBox->setMinimum(minimumValue);
  doubleSpinBox->setMaximum(maximumValue);
  doubleSpinBox->setSingleStep(0.1);
  QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), parent, functionString);
  return doubleSpinBox;
}

QSpinBox *WidgetTools::createConstantSpinBox(QWidget *parent, const size_t initialValue) {
  auto *spinBox = new QSpinBox(parent);
  spinBox->setValue(initialValue);
  spinBox->setEnabled(false);
  return spinBox;
}

QGridLayout *WidgetTools::createInspectionWidgetLayout(QWidget *parent) {
  auto *layout = new QGridLayout(parent);
  layout->setVerticalSpacing(5);
  layout->setHorizontalSpacing(10);
  layout->setContentsMargins(4, 2, 2, 4);
  return layout;
}

QLineEdit *WidgetTools::createPointerLineEdit(QWidget *parent, void *ptr) {
  auto *lineEdit = new QLineEdit(parent);
  if (ptr == nullptr) {
    lineEdit->setText("NULL");
  } else {
    std::stringstream ss;
    ss << ptr;
    std::string str;
    ss >> str;
    lineEdit->setText(QString(str.c_str()));
  }
  lineEdit->setEnabled(false);
  return lineEdit;
}
