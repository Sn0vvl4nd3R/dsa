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

using namespace SortAlgo;

static void CheckSortedEqual(const std::vector<int>& a, const std::vector<int>& b) {
  assert(a.size() == b.size());
  for (size_t i = 0; i < a.size(); ++i) {
    assert(a[i] == b[i]);
  }
}

static void TestEdgeCases(void) {
  {
    std::vector<int> a;
    auto ref = a;
    std::stable_sort(ref.begin(), ref.end());
    InsertionSort(a.begin(), a.end());
    CheckSortedEqual(a, ref);
  }

  {
    std::vector<int> a{42};
    auto ref = a;
    std::stable_sort(ref.begin(), ref.end());
    InsertionSort(a.begin(), a.end());
    CheckSortedEqual(a, ref);
  }

  {
    std::vector<int> a{1,2,3,4,5,6,7,8,9};
    auto ref = a;
    InsertionSort(a.begin(), a.end());
    CheckSortedEqual(a, ref);
  }

  {
    std::vector<int> a{9,8,7,6,5,4,3,2,1,0};
    auto ref = a; std::stable_sort(ref.begin(), ref.end());
    InsertionSort(a.begin(), a.end());
    CheckSortedEqual(a, ref);
  }

  {
    std::vector<int> a{5,1,5,5,2,2,5,1,0,0,5};
    auto ref = a;
    std::stable_sort(ref.begin(), ref.end());
    InsertionSort(a.begin(), a.end());
    CheckSortedEqual(a, ref);
  }
}

static void TestRandomInts(unsigned seed, int n, int repeats) {
  std::mt19937 rng(seed);
  std::uniform_int_distribution<int> dist(-1000000, 1000000);
  for (int r = 0; r < repeats; ++r) {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      a[i] = dist(rng);
    }
    auto ref = a; std::stable_sort(ref.begin(), ref.end());

    auto b = a;
    InsertionSort(b.begin(), b.end());
    CheckSortedEqual(b, ref);
  }
}

static void TestStrings() {
  std::vector<std::string> a{"bb", "a", "aaa", "b", "ab", "aa"};
  auto ref = a;
  std::stable_sort(ref.begin(), ref.end());
  auto b = a;
  InsertionSort(b.begin(), b.end());
  assert(b == ref);
}

int main(void) {
  TestEdgeCases();
  TestStrings();
  TestRandomInts(/*seed=*/123456u, /*n=*/5000, /*repeats=*/10);
  std::cout << "OK\n";
  return 0;
}
