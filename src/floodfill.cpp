#include <cstdlib>
#include "floodfill.hpp"

namespace floodfill {
  cell::cell() : dist(0), flags(0) {}

  bool cell::get_left() {
    return (flags & (SETBITS << LEFT)) >> LEFT;
  }

  bool cell::get_up() {
    return (flags & (SETBITS << UP)) >> UP;
  }

  bool cell::get_right() {
    return (flags & (SETBITS << RIGHT)) >> RIGHT;
  }

  bool cell::get_down() {
    return (flags & (SETBITS << DOWN)) >> DOWN;
  }

  bool cell::get_visited() {
    return flags & SETBITS;
  }

  void cell::set_left() {
    flags |= (SETBITS << LEFT);
  }

  void cell::set_up() {
    flags |= (SETBITS << UP);
  }

  void cell::set_right() {
    flags |= (SETBITS << RIGHT);
  }

  void cell::set_down() {
    flags |= (SETBITS << DOWN);
  }

  void cell::set_visited() {
    flags |= SETBITS;
  }

  std::ostream& operator<<(std::ostream& os, cell& c) {
    os << std::dec << "dist: " << c.dist << " flags: " << std::hex << c.flags;
    return os;
  }

  void init() {
    // TODO
    std::cerr << "Init called" << std::endl;
  }
}
