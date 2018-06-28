#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

#define TO_STRING(message) #message

#define THROW_STRING(message)                                                 \
  throw std::string(message) + std::string(", see") + std::string(__FILE__) + \
      std::string(", line ") + TO_STRING(__LINE__);

#endif  // EXCEPTION_H
