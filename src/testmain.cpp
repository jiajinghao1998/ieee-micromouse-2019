#include <iostream>
#include "floodfill.hpp"

using namespace std;

int main(void) {
  floodfill::cell c = floodfill::cell();
  cout << (c.get_left() ? 1 : 0) << " " << hex << c.dist << " " << (int)c.flags << endl;
  floodfill::init();
}
