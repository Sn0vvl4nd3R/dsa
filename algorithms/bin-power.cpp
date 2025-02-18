#include <iostream>

long long binpow(long long a, long long b) {
  long long result = 1;

  while (b > 0) {
    if (b & 1) {
      result *= a;
    }
    a *= a;
    b >>= 1;
  }

  return result;
}

int main(void) {
  long long a, b;
  std::cout << "Enter a and b: ";
  std::cin >> a >> b;
  std::cout << a << " in power " << b << " equals " << binpow(a, b) << '\n';
  return 0;
}
