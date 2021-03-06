#include "object.h"
#include <string>

using namespace lab3;

Object::Object() {
}

Object::Object(int X, int Y) {
  x = X;
  y = Y;
}

Object::~Object() {
  // clean up
}

int Object::getX() {
  return x;
}

int Object::getY() {
  return y;
}

std::string Object::symbol() {
  return "5";
}

std::string Object::description() {
  return "an object ";
}

//short Object::type_id() {
//  return 0;
//}

void Object::set_position(int x, int y) {
  this->x = x;
  this->y = y;
}

void Object::get_stats(int & hp, int & hunger, int & weight) {
  hp =      get_hp();
  hunger =  get_hunger();
  weight =  get_weight();
}

void Object::apply_object_to_object(Object * o) {
  hp      += o->get_hp();
  if (hp > 100) {
    hp = 100;
  }
  hunger  -= o->get_hunger();
  if (hunger < 0){
    hunger = 0;
  }
  weight  += o->get_weight();
}
