//Example uri 1286 exercise
#include <bits/stdc++.h>

using namespace std;

int dp[21][31];
int wt[30],value[20];

int knapsack(int n, int i, int p){
	if(n == i)
		return 0;

	if(dp[i][p] != -1)
		return dp[i][p];

	int tmp = knapsack(n, i+1, p);
	if(p >= wt[i])
		tmp = max(tmp, knapsack(n, i+1, p-wt[i]) + value[i]);

	return dp[i][p] = tmp;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(0);
    int n,p,min;

    while(cin >> n, n){
        cin >> p;
        for(int i = 0; i < n; i++)
            cin >> value[i] >> wt[i];
		memset(dp, -1, sizeof(dp));
        cout << knapsack(n, 0, p) << " min." << endl;
    }

    return 0;
}
