// Complexity: O(n^2)

#include <iostream>
#include <algorithm>

using namespace std;

int lengthOfLis(int *vet, int size) {
  if(!size)
    return 0;

  int dp[size], maxLen = 1;

  for(int i = 0; i < size; i++) {
    dp[i] = 1;
    for(int j = 0; j < i; j++) {
      if(vet[i] > vet[j])
        dp[i] = max(dp[i], dp[j] + 1);
    }
    maxLen = max(maxLen, dp[i]);
  }

  return maxLen;
}

int main() {

  int vet[] = { 10, 9, 2, 5, 3, 7, 101, 18 };
  int size = sizeof(vet) / sizeof(vet[0]);

  cout << lengthOfLis(vet, size) << endl;
 
  return 0;
}