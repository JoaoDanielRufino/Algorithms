#include <iostream>
#include <string.h>

using namespace std;

int dp[200][200];

int topDown(string str, int i, int j) {
  if(i > j)
    return 0;

  if(i == j)
    return 1;

  if(dp[i][j] != -1)
    return dp[i][j];

  if(str[i] == str[j])
    return dp[i][j] = 2 + topDown(str, i+1, j-1);

  return dp[i][j] = max(topDown(str, i+1, j), topDown(str, i, j-1));
}

int bottomUp(string str) {
  string str2 = str;

  reverse(str2.begin(), str2.end());

  for(int i = 0; i <= str.size(); i++) {
    for(int j = 0; j <= str2.size(); j++) {
      if(!i || !j)
         dp[i][j] = 0;
      else if(str[i-1] == str2[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];
      else
       dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
        
  return dp[str.size()][str2.size()];
}

int main() {

  string str = "bbbab";

  memset(dp, -1, sizeof(dp));

  cout << topDown(str, 0, str.size()-1) << endl;

  cout << bottomUp(str) << endl;

  return 0;
}