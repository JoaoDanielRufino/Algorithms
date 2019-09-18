// https://www.youtube.com/watch?v=dolcMgiJ7I0&feature=player_embedded
// O(sqrt(n))

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> allFactors(int n) {
  vector<int> res;

  int root = sqrt(n);
  for(int i = 1; i <= root; i++) {
    if(!(n % i)) {
      res.push_back(i);

      if(n/i != i)
        res.push_back(n/i);
    }
  }

  sort(res.begin(), res.end());

  return res;
}

using namespace std;

int main() {

  int n = 24;

  vector<int> factors = allFactors(n);

  for(int i = 0; i < factors.size(); i++) {
    cout << factors[i] << " ";
  }

  cout << endl;

  return 0;
}