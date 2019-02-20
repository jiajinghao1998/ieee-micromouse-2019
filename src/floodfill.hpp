#ifndef FLOOD_FILL_HPP
#define FLOOD_FILL_HPP
#include <stack>
#include <cstdint>
#include <iostream>

namespace floodfill {
  /* Constant global variables */
  const int SIDE_LENGTH = 5;
  const int LEFT = 4;
  const int UP = 3;
  const int RIGHT = 2;
  const int DOWN = 1;
  const uint8_t SETBITS = 0x01;

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

  // Actual maze
  extern cell maze[SIDE_LENGTH][SIDE_LENGTH];

  // Stack to use in the algo
  extern std::stack<cell> st;

  // Functions
  void init();
  uint8_t m_dist(uint8_t, uint8_t, uint8_t, uint8_t);
}

#endif
