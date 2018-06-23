#include "viewwidget.h"

#include <QVBoxLayout>

ViewWidget::ViewWidget(OpenGlWidget *openGlWidget, QWidget *parent)
    : QWidget(parent), _openGlWidget(openGlWidget) {
  setLayout(new QVBoxLayout);
  layout()->setContentsMargins(0, 0, 0, 0);
  layout()->setSpacing(1);
}
