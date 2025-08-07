#pragma once
#include <concepts>
#include <functional>
#include <iterator>

namespace SortAlgo {

  template <std::random_access_iterator It, class Compare = std::less<>>
  void BubbleSort(It first, It last, Compare comp = Compare{}) {
    if (first == last) {
      return;
    }

    It n = last;
    while (true) {
      bool swapped = false;
      It new_n = first;
      for (It i = first + 1; i < n; ++i) {
        It prev = i - 1;
        if (comp(*i, *prev)) {
          std::iter_swap(i, prev);
          swapped = true;
          new_n = i;
        }
      }
      n = new_n;
      if (!swapped) {
        break;
      }
    }
  }

}
