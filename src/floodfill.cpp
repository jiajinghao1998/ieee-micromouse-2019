#include <iomanip>
#include <cmath>
#include "floodfill.hpp"

namespace floodfill {
  cell::cell() : dist(0), flags(0) {}

  bool cell::get_wall_flag(direction dir) {
    switch (dir) {
      case direction::LEFT:
        return (flags & (KEY << LEFT_BIT_IDX)) >> LEFT_BIT_IDX;
      case direction::UP:
        return (flags & (KEY << UP_BIT_IDX)) >> UP_BIT_IDX;
      case direction::RIGHT:
        return (flags & (KEY << RIGHT_BIT_IDX)) >> RIGHT_BIT_IDX;
      case direction::DOWN:
        return (flags & (KEY << DOWN_BIT_IDX)) >> DOWN_BIT_IDX;
    }
    return false;
  }

  bool cell::get_visited() {
    return flags & KEY;
  }

  void cell::set_wall_flag(direction dir, bool on) {
    switch (dir) {
      case direction::LEFT:
        flags |= on ? (KEY << LEFT_BIT_IDX) : ~(KEY << LEFT_BIT_IDX);
      case direction::UP:
        flags |= on ? (KEY << UP_BIT_IDX) : ~(KEY << UP_BIT_IDX);
      case direction::RIGHT:
        flags |= on ? (KEY << RIGHT_BIT_IDX) : ~(KEY << RIGHT_BIT_IDX);
      case direction::DOWN:
        flags |= on ? (KEY << DOWN_BIT_IDX) : ~(KEY << DOWN_BIT_IDX);
    }
  }

  void cell::set_visited() {
    flags |= KEY;
  }

  std::ostream& operator<<(std::ostream& os, cell& c) {
    os.fill('0');
    os << c.dist << " 0x" << std::hex << std::setw(4) << (int)c.flags;
    return os;
  }

  cell maze[SIDE_LENGTH][SIDE_LENGTH];
  std::stack<cell> st;

  void init() {
    const uint8_t mid = SIDE_LENGTH / 2;
    for(uint8_t i = 0; i < SIDE_LENGTH; ++i) {
      for(uint8_t j = 0; j < SIDE_LENGTH; ++j) {
        maze[i][j] = cell();
        maze[i][j].dist = m_dist(i, j, mid, mid);
      }
    }
    print_maze(std::cout);
  }

  uint8_t m_dist(uint8_t r1, uint8_t c1, uint8_t r2, uint8_t c2) {
    return abs(r1 - r2) + abs(c1 - c2);
  }

  void print_maze(std::ostream& os) {
    os.fill(' ');
    for(uint8_t i = 0; i < SIDE_LENGTH; ++i) {
      os << "+";
      for(uint8_t j = 0; j < SIDE_LENGTH; ++j) {
        os << (maze[i][j].get_wall_flag(direction::UP) ? "---" : "   ") << "+";
      }
      os << "\n" << (maze[i][0].get_wall_flag(direction::LEFT) ? "|" : " ");
      for(uint8_t j = 0; j < SIDE_LENGTH; ++j) {
        os << std::setw(3) << (int)maze[i][j].dist
           << (maze[i][j].get_wall_flag(direction::RIGHT) ? "|" : " ");
      }
      os << "\n";
    }
    os << "+";
    for(uint8_t j = 0; j < SIDE_LENGTH; ++j) {
      os << (maze[SIDE_LENGTH - 1][j].get_wall_flag(direction::DOWN) ?
             "---" : "   ") << "+";
    }
    os << std::endl;
  }
}
