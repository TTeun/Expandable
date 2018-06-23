#ifndef VERTEX_H
#define VERTEX_H

#include <QVector2D>

class QString;

class Vertex {
 public:
  Vertex();

  Vertex(double x, double y, size_t index) : _x(x), _y(y), _index(index) {
  }

  static const QString &getName();

  double getX() const;
  void setX(double x);
  double getY() const;
  void setY(double y);
  size_t getIndex() const;

 private:
  double _x = 0.;
  double _y = 0.;
  size_t _index = 0u;
};

#endif  // VERTEX_H
