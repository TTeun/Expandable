#ifndef VERTEX_H
#define VERTEX_H

#include <QDebug>
#include <QString>
#include <QVector2D>

class Vertex {
 public:
  Vertex();

  static const QString getName() {
    return "Vertex";
  }

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
