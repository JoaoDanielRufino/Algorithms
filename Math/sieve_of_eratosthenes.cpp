// O(nlog(log(n)))

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> sieve(int n) {
  vector<int> primes(n+1, 1);
  vector<int> res;
    
    primes[0] = 0;
    primes[1] = 0;
    
    int root = sqrt(n);
    for(int i = 2; i <= root; i++) {
        if(primes[i]) {
            for(int j = i*i; j <= n; j += i)
                primes[j] = 0;
        }
    }
    
    for(int i = 0; i < primes.size(); i++) {
        if(primes[i])
            res.push_back(i);
    }
    
    return res;
}

using namespace std;

int main() {

  int n = 181;

  vector<int> primes = sieve(n);

  for(int i = 0; i < primes.size(); i++)
    cout << primes[i] << " ";

  cout << endl;

  return 0;
}