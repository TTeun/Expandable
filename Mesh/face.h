#ifndef FACE_H
#define FACE_H

#include <QString>

class Face {
 public:
  Face();

  static const QString getName() {
    return "Face";
  }

  size_t getVal() const;
  size_t getIndex() const;

 private:
  size_t _val = 4;
  size_t _index = 0u;
};

#endif  // FACE_H
