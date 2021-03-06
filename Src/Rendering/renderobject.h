#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QVector4D>
#include <QVector>

#include <memory>

class SimpleShader;

class RenderObject {
 public:
  enum Render_Mode : size_t { Points = 1u, Lines = 2u, End = 4u };

  enum Render_Position : uint { Top_Left, Bottom_Left, Top_Right, Bottom_Right, Right, Whole };

  RenderObject(Render_Position renderPosition = Whole);
  virtual ~RenderObject();

  static QString getNameOfRenderMode(Render_Mode renderMode);

  bool isInitialized();

  virtual size_t objectCount();
  virtual void render(QOpenGLFunctions *f);
  virtual void initialize(QOpenGLFunctions *f);
  virtual void update();
  virtual void fillData();
  virtual void cleanUp();

  void needsUpdate(bool needsUpdate);
  void toggleRenderMode(RenderObject::Render_Mode renderMode, bool value);
  void setTransform(Render_Position renderPosition);
  void setTransform(float dx, float dy, float scale = 1.0);
  void setColour(float r, float g, float b, float alpha = 1.0);

  std::unique_ptr<SimpleShader> _simpleShader;

 protected:
  void initializeBase(QOpenGLFunctions *f);
  virtual void renderObject(RenderObject::Render_Mode renderMode) = 0;

  bool _uniformsNeedUpdate = true;

  float _dx = 0.;
  float _dy = 0.;
  float _scale;
  QVector4D _color = QVector4D(0., 0., 0., 1.);

  QOpenGLVertexArrayObject _vao;

  QOpenGLBuffer _vertexPositionBufferObject;
  QOpenGLBuffer _indexBufferObject;

  QVector<GLfloat> _positionData;
  QVector<GLushort> _indices;

  size_t _renderMode = Render_Mode::Lines;
  bool _needsUpdate;
  bool _isInitialized = false;
};

#endif  // RENDEROBJECT_H
