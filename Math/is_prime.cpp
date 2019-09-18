// O(sqrt(n))

#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
  if(n == 1)
    return false;

  int root = sqrt(n);
  for(int i = 2; i <= root; i++) {
    if(!(n % i))
      return false;
  }

  return true;
}

using namespace std;

int main() {

  int n = 181;

  cout << isPrime(n) << endl;

  return 0;
}