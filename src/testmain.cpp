#include <iostream>
#include "floodfill.hpp"

using namespace std;

int main(void) {
  floodfill::maze[0][0] = floodfill::cell();
  cout << (floodfill::maze[0][0].get_wall_flag(floodfill::direction::LEFT)
           ? 1 : 0) << floodfill::maze[0][0] << endl;
  floodfill::init();
  cout << (int)floodfill::m_dist(1, 2, 3, 4) << endl;
}
