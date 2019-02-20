#include <cstdlib>
#include <iomanip>
#include <cmath>
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
    os.fill('0');
    os << c.dist << " 0x" << std::hex << std::setw(4) << (int)c.flags;
    return os;
  }

  cell maze[SIDE_LENGTH][SIDE_LENGTH];
  std::stack<cell> st;

  void init() {
    // TODO
    std::cerr << "Init called" << std::endl;
  }

  uint8_t m_dist(uint8_t r1, uint8_t c1, uint8_t r2, uint8_t c2) {
    return abs(r1 - r2) + abs(c1 - c2);
  }
}
