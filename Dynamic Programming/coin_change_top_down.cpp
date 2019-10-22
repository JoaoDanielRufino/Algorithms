#include <bits/stdc++.h>

using namespace std;

int dp[10005][5]; //Max value+1 | qty of coins.

long long int coin_change(vector<int> vet, int value, int index){
    if(!value)
        return 1;

    if(value < 0 || index == vet.size())
        return 0;

    if(dp[value][index] != -1)
        return dp[value][index];

    return dp[value][index] = coin_change(vet, value-vet[index], index) + coin_change(vet, value, index+1);
}

int main(){

    ios::sync_with_stdio(false); cin.tie(0);
    int val;
    vector<int> vet;

    vet.push_back(1); //Example of coins.
    vet.push_back(5);
    vet.push_back(10);
    vet.push_back(25);
    vet.push_back(50);
    memset(dp, -1, sizeof dp);

    while(cin >> val){
        cout << coin_change(vet, val, 0) << endl;
    }

    return 0;
}
