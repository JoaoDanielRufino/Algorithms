#include <iostream>
#include <string.h>

using namespace std;

int dp[100][100];

int topDown(string x, string y, int i, int j) {
  if(i >= x.size() || j >= y.size())
    return 0;

  if(dp[i][j] != -1)
    return dp[i][j];

  if(x[i] == y[j])
    return dp[i][j] = 1 + topDown(x, y, i + 1, j + 1);

  return dp[i][j] = max(topDown(x, y, i + 1, j), topDown(x, y, i, j + 1));
}

int bottomUp(string x, string y) {
  for(int i = 0; i <= x.size(); i++) {
    for(int j = 0; j <= y.size(); j++) {
      if(!i || !j)
        dp[i][j] = 0;
      else if(x[i-1] == y[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
        
  return dp[x.size()][y.size()];
}

int main() {

  string x = "AGGTAB";
  string y = "GXTXAYB";

  memset(dp, -1, sizeof(dp));

  cout << topDown(x, y, 0, 0) << endl;

  cout << bottomUp(x, y) << endl;

  return 0;
}