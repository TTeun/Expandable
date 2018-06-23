#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "../Rendering/meshrenderobject.h"

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <memory>
#include <vector>

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class OpenGlWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  OpenGlWidget(QWidget *parent = 0);
  ~OpenGlWidget();

  QSize minimumSizeHint() const override;
  QSize sizeHint() const override;

 public slots:
  void cleanup();

 signals:

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int width, int height) override;

 private:
  std::vector<std::unique_ptr<RenderObject>> _renderObjects;
  QOpenGLShaderProgram *m_program;
};

#endif
