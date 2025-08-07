#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstddef>
#include <iostream>
#include <random>
#include <string>
#include <utility>
#include <vector>

#include "../include/sort_algo/insertion_sort.hpp"
#include "../include/sort_algo/bubble_sort.hpp"

using namespace SortAlgo;

template <class Vec>
void CheckSortedEqual(const Vec& a, const Vec& b) {
  assert(a.size() == b.size());
  for (std::size_t i = 0; i < a.size(); ++i) {
    assert(a[i] == b[i]);
  }
}

template <class It, class Compare = std::less<>>
void RunAll(It first, It last, Compare comp = Compare{}) {
  using v = typename std::iterator_traits<It>::value_type;
  std::vector<v> base(first, last);
  std::vector<v> ref = base;
  std::stable_sort(ref.begin(), ref.end(), comp);

  auto TestOne = [&](auto&& sort_fn) {
    auto a = base;
    sort_fn(a.begin(), a.end(), comp);
    CheckSortedEqual(a, ref);
  };

  TestOne([](auto b, auto e, auto c) {
    InsertionSort(b, e, c);
  });
  TestOne([](auto b, auto e, auto c) {
    BubbleSort(b, e, c);
  });
}

static void TestEdgeCases(void) {
  RunAll(std::vector<int>{}.begin(), {});
  RunAll(std::vector<int>{42}.begin(), std::vector<int>{42}.end());
  RunAll(std::vector<int>{1,2,3,4,5}.begin(), std::vector<int>{1,2,3,4,5}.end());
  RunAll(std::vector<int>{5,4,3,2,1}.begin(), std::vector<int>{5,4,3,2,1}.end());
  RunAll(std::vector<int>{1,1,1,1,1}.begin(), std::vector<int>{1,1,1,1,1}.end());
}

static void TestRandomInts(unsigned seed, int n, int repeats) {
  std::mt19937 rng(seed);
  std::uniform_int_distribution<int> dist(-1000000, 1000000);
  for (int r = 0; r < repeats; ++r) {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = dist(rng);
    }
    RunAll(a.begin(), a.end());
  }
}

static void TestStrings() {
  std::vector<std::string> a{"bb", "a", "aaa", "b", "ab", "aa"};
  RunAll(a.begin(), a.end());
}

int main(void) {
  TestEdgeCases();
  TestStrings();
  TestRandomInts(/*seed=*/123456u, /*n=*/5000, /*repeats=*/10);
  std::cout << "OK\n";
  return 0;
}
