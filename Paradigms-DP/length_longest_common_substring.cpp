#include <iostream>
#include <string.h>

using namespace std;

int solve(string x, string y, int m, int n) {
  int dp[m+1][n+1];
  int maxLen = 0;

  for(int i = 0; i <= m; i++) {
    for(int j = 0; j <= n; j++) {
      if(!i || !j)
        dp[i][j] = 0;
      else if(x[i-1] == y[j-1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
        maxLen = max(maxLen, dp[i][j]);
      }
      else
        dp[i][j] = 0;
    }
  }

  return maxLen;
}

int main() {

  string x = "OldSite:GeeksforGeeks.org";
  string y = "NewSite:GeeksQuiz.com";

  cout << solve(x, y, x.size(), y.size()) << endl;

  return 0;
}