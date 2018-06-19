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

QDoubleSpinBox *WidgetTools::createDoubleSpinBox(const double initialValue,
                                                 QWidget *parent,
                                                 const char *functionString) {
  auto *doubleSpinBox = new QDoubleSpinBox(parent);
  doubleSpinBox->setValue(initialValue);
  QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), parent, functionString);
  return doubleSpinBox;
}

QSpinBox *WidgetTools::createConstantSpinBox(const size_t value, QWidget *parent) {
  auto *spinBox = new QSpinBox(parent);
  spinBox->setValue(value);
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

QLineEdit *WidgetTools::createPointerLineEdit(void *ptr, QWidget *parent) {
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
