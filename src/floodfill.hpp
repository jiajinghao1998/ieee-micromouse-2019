#ifndef FLOOD_FILL_HPP
#define FLOOD_FILL_HPP
#include <stack>
#include <cstdint>
#include <iostream>

namespace floodfill {
  /* Constant global variables */
  const uint8_t SIDE_LENGTH = 5;
  const int LEFT_BIT_IDX = 4;
  const int UP_BIT_IDX = 3;
  const int RIGHT_BIT_IDX = 2;
  const int DOWN_BIT_IDX = 1;
  const uint8_t KEY = 0x01;

  /* Directions for walls */
  enum class direction : int {
    LEFT,
    UP,
    RIGHT,
    DOWN
  };

  /* Represents cells */
  struct cell {
  public:
    uint8_t dist;
    uint8_t flags; // 0 0 0 left up right down visited

    // Constructor
    cell();

    // Util functions
    bool get_wall_flag(direction);
    bool get_visited();
    void set_wall_flag(direction, bool);
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
  void print_maze(std::ostream&);
}

#endif
