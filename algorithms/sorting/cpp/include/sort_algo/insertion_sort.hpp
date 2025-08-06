#pragma once
#include <concepts>
#include <functional>
#include <iterator>

namespace SortAlgo {

  template <std::random_access_iterator It, class Compare = std::less<>>
  void InsertionSort(It first, It last, Compare comp = Compare{}) {
    if (first == last) {
      return;
    }
    
    for (It i = first + 1; i < last; ++i) {
      auto key = *i;
      It j = i;

      while (j > first && comp(key, *(j - 1))) {
        *j = *(j - 1);
        --j;
      }
      *j = key;
    }
  }

}
