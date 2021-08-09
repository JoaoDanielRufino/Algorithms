// https://leetcode.com/problems/knight-dialer/

class Solution {
public:
    int dx[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
    int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};
    int mod = 1000000007;
    int dp[50001][4][3] = {0};
    
    int ok(int i, int j) {
        if(i < 0 || i >= 4)
            return false;
        
        if(j < 0 || j >= 3)
            return false;
        
        if(i == 3 && j == 0 || i == 3 && j == 2)
            return false;
        
        return true;
    }
    
    int solve(int i, int j, int n) {
        if(!ok(i, j))
            return 0;
        
        if(!n)
            return 1;
        
        if(dp[n][i][j])
            return dp[n][i][j];
        
        int res = 0;
        for(int k = 0; k < 8; k++)
            res = (res + solve(i + dx[k], j + dy[k], n-1)) % mod;
        
        return dp[n][i][j] = res;
    }
    
    int knightDialer(int n) {
        int res = 0;
        
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                res = (res + solve(i, j, n-1)) % mod;
            }
        }
        
        return res;
    }
};
