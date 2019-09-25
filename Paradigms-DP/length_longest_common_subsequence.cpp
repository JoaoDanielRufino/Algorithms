#include <iostream>
#include <string.h>

using namespace std;

int dp[100][100];

int solve(string x, string y, int i, int j) {
  if(i >= x.size() || j >= y.size())
    return 0;

  if(dp[i][j] != -1)
    return dp[i][j];

  if(x[i] == y[j])
    return dp[i][j] = 1 + solve(x, y, i + 1, j + 1);

  return dp[i][j] = max(solve(x, y, i + 1, j), solve(x, y, i, j + 1));
}

int main() {

  string x = "AGGTAB";
  string y = "GXTXAYB";

  memset(dp, -1, sizeof(dp));

  cout << solve(x, y, 0, 0) << endl;

  return 0;
}