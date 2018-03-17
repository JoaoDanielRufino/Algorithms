//Example of uri 1286 exercise
#include <bits/stdc++.h>

using namespace std;

int T[21][31];

int knapsack(int p, int *wt, int *value, int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=p; j++){
            if(i==0 || j==0)
                T[i][j] = 0;
                
            else if(wt[i-1] > j)
                T[i][j] = T[i-1][j];
                
            else
                T[i][j] = max(value[i-1] + T[i-1][j-wt[i-1]], T[i-1][j]);
        }
    }
    return T[n][p];
}

int main(){

    ios::sync_with_stdio(false); cin.tie(0);
    int n,p,min;

    while(cin >> n, n){
        cin >> p;
        int wt[30],value[20];
        
        for(int i=0; i<n; i++)
            cin >> value[i] >> wt[i];
            
        min = knapsack(p,wt,value,n);
        cout << min << " min." << endl;
    }

    return 0;
}
