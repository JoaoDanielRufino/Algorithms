// Greatest common divisor
// https://en.wikipedia.org/wiki/Greatest_common_divisor

#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if(!b)
    return a;
  
  return gcd(b, a % b);
}

int main() {

  cout << gcd(60, 36) << endl;

  return 0;
}