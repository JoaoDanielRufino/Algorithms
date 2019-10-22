// This algorithm finds the best subset sum to a value N (sum <= N)
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=565

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int dp[22][1000];
int N;
vector<int> vet;

int solve(int sum, int index) {
  if(sum > N)
    return 0;

  if(sum == N || index == vet.size())
    return dp[index][sum] = sum;

  if(dp[index][sum] != -1)
    return dp[index][sum];

  int res = max(solve(sum, index+1), solve(sum + vet[index], index+1));

  return dp[index][sum] = res;
}

void print(int i, int j, int res) {
  if(i == vet.size() || j == res)
    return;

  if(dp[i+1][j + vet[i]] == res) {
    cout << vet[i] << " ";
    print(i+1, j + vet[i], res);
  }
  else
    print(i+1, j, res);
}

int main() {

  ios::sync_with_stdio(false); //cin.tie(0);
  int a, n;

  while(cin >> N) {
    cin >> n;
    while(n--) {
      cin >> a;
      vet.push_back(a);
    }

    memset(dp, -1, sizeof(dp));

    int res = solve(0, 0);

    print(0, 0, res);
    cout << "sum:" << res << endl;
    
    vet.clear();
  }

  return 0;
}