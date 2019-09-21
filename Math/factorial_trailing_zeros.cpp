#include <iostream>

using namespace std;

int trailingZeroes(int n) {
  int zeros = 0;

  while(n >= 5) {
    zeros += n/5;
    n /= 5;
  }

  return zeros;
}

int main() {

  int n;

  cin >> n;

  cout << trailingZeroes(n) << endl;

  return 0;
}