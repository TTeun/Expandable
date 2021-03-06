#include "gridwidget.h"

#include "widgettools.h"

#include <QGridLayout>

GridWidget::GridWidget(QWidget *parent)
    : QGroupBox(parent), _layout(WidgetTools::createInspectionWidgetLayout(this)) {
  setStyleSheet(
      "QGroupBox{"
      "  background-color: rgb(250,250,250);"
      "  border-style: outset;"
      "  border-width: 1px;"
      "  border-color: rgb(80,80,80);"
      "}");
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
  setLayout(_layout);
}
