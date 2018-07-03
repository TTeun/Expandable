#ifndef GRIDWIDGET_H
#define GRIDWIDGET_H

#include <QGroupBox>

class QGridLayout;

class GridWidget : public QGroupBox {
  Q_OBJECT
 public:
  GridWidget(QWidget *parent);

 protected:
  QGridLayout *_layout;
};

#endif  // GRIDWIDGET_H
