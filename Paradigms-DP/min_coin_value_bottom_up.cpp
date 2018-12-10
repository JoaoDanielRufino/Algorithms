#include <bits/stdc++.h>
#define INF 101010

using namespace std;

int dp[50001];

int solve(int val, vector<int> vet){
  int tmp;

  for(int i = 1; i <= val; i++){
    for(int j = 0; j < vet.size(); j++){
      if(vet[j] <= i){
        tmp = dp[i-vet[j]];
        if(tmp+1 < dp[i] && tmp != INF)
        dp[i] = tmp + 1;
      }
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
