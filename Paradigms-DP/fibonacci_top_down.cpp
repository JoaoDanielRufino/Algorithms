#include <iostream>
#include <string.h>

using namespace std;

long long int dp[90];

long long int fib(int n) {
  if(!n)
    return 0LL;

  if(n == 1)
    return 1LL;

  if(dp[n] != -1)
    return dp[n];

  return dp[n] = fib(n-1) + fib(n-2);
}

int main() {

  int n;

  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  dp[1] = 1;

  while(cin >> n) {
    cout << "Fib[" << n << "] = " << fib(n) << endl;
  }

  return 0;
}