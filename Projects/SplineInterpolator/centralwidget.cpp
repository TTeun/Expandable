#include "centralwidget.h"

#include "Widgets/openglwidget.h"

#include <QDebug>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPalette>
#include <QSlider>
#include <QVBoxLayout>

CentralWidget::CentralWidget(QWidget* parent)
    : QWidget(parent), _openGlWidget(new OpenGlWidget(this)) {
  setObjectName("centralWidget");
  auto* layout = createLayout();
  layout->addWidget(createGroupBox());
  layout->addWidget(_openGlWidget);
  setLayout(layout);
  raise();
}

CentralWidget::~CentralWidget() {
}

QGroupBox* CentralWidget::createGroupBox() {
  auto* groupBox = new QGroupBox("GoPhEr");
  QVBoxLayout* leftLayout = new QVBoxLayout;
  leftLayout->setAlignment(Qt::AlignTop);
  groupBox->setLayout(leftLayout);
  {
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::gray);
    groupBox->setAutoFillBackground(true);
    groupBox->setPalette(pal);
  }
  groupBox->setMinimumWidth(300);
  groupBox->setMaximumWidth(400);
  groupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
  groupBox->setFixedWidth(300);
  leftLayout->setSpacing(10);
  leftLayout->setContentsMargins(5, 10, 5, 10);
  return groupBox;
}

QLayout* CentralWidget::createLayout() {
  auto* layout = new QHBoxLayout;
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);
  setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  return layout;
}
