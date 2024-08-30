//
// Copyright (C) 2019 Rian Quinn <user@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// -----------------------------------------------------------------------------
#ifdef EXAMPLE01

#include <iostream>
#include <string>
class spiderman {
public:
  bool attack(int x, int) const { return x == 0 ? true : false; }
  std::string name() const { return std::string{"spiderman"}; }
};

class captain_america {
public:
  bool attack(int, int y) const { return y == 0 ? true : false; }
  std::string name() const { return std::string{"captain_america"}; }
};

template <typename T> auto attack(const T &t, int x, int y) {
  if (t.attack(x, y)) {
    std::cout << "hero " << t.name() << " won fight\n";
  } else {
    std::cout << "hero " << t.name() << "lost the fight :(\n";
  }
}

int main(void) {
  attack(spiderman{}, 0, 42);
  attack(captain_america{}, 0, 42);

  return 0;
}

// hero won fight
// hero lost the fight :(

#endif
