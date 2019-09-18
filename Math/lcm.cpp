// Least Common Multiple

#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if(!b)
    return a;
  
  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

int main() {

  cout << lcm(7, 5) << endl;

  return 0;
}