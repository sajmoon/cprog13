#ifndef OBJECT_H
#define OBJECT_H

#include <string>

namespace lab3 {
  class Object {
    protected:
    public:
      int x, y;
      char sym;
      Object();
      Object(int, int);

      int getX();
      int getY();

      virtual std::string symbol();

      void set_position(int x, int y);
      
  };
}
#endif
