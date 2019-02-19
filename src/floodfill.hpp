#ifndef FLOOD_FILL_HPP
#define FLOOD_FILL_HPP
#include <stack>
#include <cstdint>
#include <iostream>

/* Constant global variables */
const int SIDE_LENGTH = 5;
const int LEFT = 4;
const int UP = 3;
const int RIGHT = 2;
const int DOWN = 1;
const uint8_t SETBITS = 0x01;

namespace floodfill {
  /* Represents cells */
  struct cell {
  public:
    uint8_t dist;
    uint8_t flags; // 0 0 0 left up right down visited

    cell();

    // Util functions
    bool get_left();
    bool get_up();
    bool get_right();
    bool get_down();
    bool get_visited();
    void set_left();
    void set_up();
    void set_right();
    void set_down();
    void set_visited();

    friend std::ostream& operator<<(std::ostream&, cell&);
  };
  std::ostream& operator<<(std::ostream&, cell&);
  void init();
}

#endif
