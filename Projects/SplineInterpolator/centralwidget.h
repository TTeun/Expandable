#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>

#include <memory>

class QGroupBox;
class QLayout;
class OpenGlWidget;

class CentralWidget : public QWidget {
  Q_OBJECT

 public:
  explicit CentralWidget(QWidget *parent = nullptr);

  ~CentralWidget();

 private:
  QGroupBox *createGroupBox();
  QLayout *createLayout();
  OpenGlWidget *_openGlWidget;
};

#endif  // CENTRALWIDGET_H
