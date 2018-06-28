#ifndef VERTEX_H
#define VERTEX_H

#include <QVector2D>

#include <limits>

class QString;

class Vertex {
 public:
  Vertex();

  Vertex(double x, double y, size_t index) : _x(x), _y(y), _index(index) {
  }

  static const QString &getName();

  double getX() const;
  double getY() const;
  double getZ() const;

  void setX(double x);
  void setY(double y);
  void setZ(double z);

  size_t getIndex() const;

 private:
#define declareCoordinate(name) #name

  double _x = 1.;
  double _y = 1.;
  double _z = 1.;
  size_t _index = std::numeric_limits<size_t>::max();
};

#endif  // VERTEX_H
