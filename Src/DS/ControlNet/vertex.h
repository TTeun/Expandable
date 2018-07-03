#ifndef VERTEX_H
#define VERTEX_H

#include <limits>

#include <QVector2D>

class Vertex : public QVector2D {
 public:
  Vertex(const QVector2D &position, size_t index = std::numeric_limits<size_t>::max());

  size_t index() const;
  void setIndex(const size_t &index);

  Vertex *operator+=(const QVector2D &other) {
    *(static_cast<QVector2D *>(this)) += other;
    return this;
  }

 private:
  size_t _index = std::numeric_limits<size_t>::max();
};

#endif  // VERTEX_H
