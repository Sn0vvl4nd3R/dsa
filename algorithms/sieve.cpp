#include <iostream>
#include <vector>

std::vector<int> sieve(int n) {
  std::vector<bool> IsPrime(n + 1, true);
  std::vector<int> primes;

  if (n < 2) {
    return primes;
  }

  IsPrime[0] = IsPrime[1] = false;

  for (int i = 2; i * i <= n; i++) {
    if (IsPrime[i]) {
      for (int j = i * i; j <= n; j += i) {
        IsPrime[j] = false;
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    if (IsPrime[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}

int main(void) {
  int n = 0;
  std::cout << "Enter the number n: ";
  std::cin >> n;

  std::vector<int> primes = sieve(n);

  std::cout << "Prime numbers till " << n << ":\n";
  for (int prime : primes) {
    std::cout << prime << ' ';
  }
  std::cout << '\n';

  return 0;
}
