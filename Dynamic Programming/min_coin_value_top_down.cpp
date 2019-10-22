// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

#include <bits/stdc++.h>
#define INF 101010

using namespace std;

int dp[50001];

int solve(int val, vector<int> vet){
  if(!val)
    return 0;

  if(dp[val] != INF)
    return dp[val];

  for(int i = 0; i < vet.size(); i++){
    if(vet[i] <= val){
        dp[val] = min(dp[val], 1 + solve(val-vet[i], vet));
    }
  }

  return dp[val];
}

int main(){

  ios::sync_with_stdio(false); cin.tie(0);
  int m,n,a;
  vector<int> vet;

  while(cin >> m, m){
    cin >> n;
    while(n--){
      cin >> a;
      vet.push_back(a);
    }

    for(int i = 1; i <= m; i++)
      dp[i] = INF;

    dp[0] = 0;
    int res = solve(m, vet);
    if(res == INF)
      cout << "Impossivel" << endl;
    else
      cout << res << endl;

    vet.clear();
  }

  return 0;
}
