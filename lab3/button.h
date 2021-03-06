#ifndef BUTTON_H
#define BUTTON_H

#include "object.h"
#include <string>
#include "teleporter.h"

namespace lab3 {
  class Button : public Object {
    protected:
      bool pressed;
    public:
      Button() : Object() {
        pressed = false;
      };
      Button( int x, int y ) : Object(x,y) {
        pressed = false;
      };


      virtual std::string symbol()      {
        if (pressed) {
          return "b";
        }
        return "B";
      };
      virtual short type_id()           { return 7; };
      virtual std::string description();
      
      virtual bool can_do_action()      { return !pressed; }
      virtual std::string action_description() {
        if (pressed) {
          return "have already pressed";
        }

        pressed = true;
        return "pressed";
      };
      virtual Object * perform_action() { return new Teleporter(10,10);};

      virtual bool actionable() { return true; };
      virtual bool passable()   { return true; };
  };
}
#endif
