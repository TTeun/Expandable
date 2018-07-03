#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>

class OpenGlWidget;

class ViewWidget : public QWidget {
  Q_OBJECT
 public:
  explicit ViewWidget(OpenGlWidget *openGlWidget, QWidget *parent);

 private:
  OpenGlWidget *_openGlWidget;
};

#endif  // VIEWWIDGET_H
