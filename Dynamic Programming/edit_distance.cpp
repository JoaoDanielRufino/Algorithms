// https://www.geeksforgeeks.org/edit-distance-dp-5/

#include <iostream>

using namespace std;

int dp[500][500];

int solve(string s1, string s2, int i, int j) {
  if(!i)
    return j;

  if(!j)
    return i;

  if(dp[i][j] != -1)
    return dp[i][j];

  if(s1[i-1] == s2[j-1])
    return dp[i][j] = solve(s1, s2, i-1, j-1);

  int insert = solve(s1, s2, i, j-1);
  int remove = solve(s1, s2, i-1, j);
  int replace = solve(s1, s2, i-1, j-1);

  return dp[i][j] = 1 + min(insert, min(remove, replace));
}

int main() {

  string s1 = "intention";
  string s2 = "execution";

  for(int i = 0; i <= s1.size(); i++) {
    for(int j = 0; j <= s2.size(); j++) {
      dp[i][j] = -1;
    }
  }

  cout << solve(s1, s2, s1.size(), s2.size()) << endl;

  return 0;
}