//
// Copyright (C) 2019 Rian Quinn <rianquinn@gmail.com>
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

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  auto list = std::vector<int>{{4, 8, 15, 16, 23, 42}};
  std::cout << std::ranges::count(list.begin(), list.end(), 42) << '\n';
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE02

#include <algorithm>
#include <iostream>
namespace ranges = std::ranges;
int main(void) {
  auto list = {4, 8, 15, 16, 23, 42};
  if (auto i = ranges::find(list, 42); i != ranges::end(list)) {
    std::cout << *i << '\n';
  }
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE03

#include <algorithm>
#include <iostream>
int main(void) {
  namespace ranges = std::ranges;
  int list[] = {4, 8, 15, 16, 23, 42};
  if (auto i = ranges::find(list, 42); i != ranges::end(list)) {
    std::cout << *i << '\n';
  }
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE04

#include <algorithm>
#include <iostream>
int main(void) {
  namespace ranges = std::ranges;
  auto list = {4, 8, 15, 16, 23, 42};

  ranges::for_each(list, [](const int &val) { std::cout << val << ' '; });

  std::cout << '\n';
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE05

#include <algorithm>
#include <iostream>
#include <vector>
#
class my_type {
  int m_i;

public:
  my_type(int i) : m_i{i} {}

  auto get() const { return m_i; }
};

int main(void) {
  namespace ranges = std::ranges;
  using namespace ranges::views;

  auto list1 = {4, 8, 15, 16, 23, 42};
  std::vector<my_type> list2(list1.size(), 0);
  std::transform(list1.begin(), list1.end(), list2.begin(),
                 [](int val) { return my_type(val); });

  for (const auto &elem : list2) {
    std::cout << elem.get() << ' ';
  }

  std::cout << '\n';
}

#endif

// -----------------------------------------------------------------------------
#ifdef EXAMPLE06

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  namespace ranges = std::ranges;
  std::vector<int> list = {4, 42, 15, 8, 23, 16};
  // list |= actions::sort;

  for (const auto &elem : list) {
    std::cout << elem << ' ';
  }

  std::cout << '\n';
}

#endif
