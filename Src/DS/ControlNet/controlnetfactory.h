#ifndef CONTROLNETFACTORY_H
#define CONTROLNETFACTORY_H

class ControlNet;

class ControlNetFactory {
 public:
  ControlNetFactory() = delete;

  static ControlNet* createSquare();
};

#endif  // CONTROLNETFACTORY_H
