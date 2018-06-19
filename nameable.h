#ifndef NAMEABLE_H
#define NAMEABLE_H

#include <QDebug>
#include <string>

class Nameable {
 public:
  Nameable(const std::string& name) : _name(name) {
    qDebug() << "++" << _name.c_str() << " constructor";
  }

  ~Nameable() {
    qDebug() << "--" << _name.c_str() << " destructor";
  }

  const std::string& getName() const {
    return _name;
  }

 private:
  const std::string _name;
};

#define NAME_CLASS(name) const Nameable name::_nameable(#name);

#define IS_NAMED                       \
 private:                              \
  static const Nameable _nameable;     \
                                       \
 public:                               \
  const std::string& getName() const { \
    return _nameable.getName();        \
  }                                    \
                                       \
 private:

#endif  // NAMEABLE_H
