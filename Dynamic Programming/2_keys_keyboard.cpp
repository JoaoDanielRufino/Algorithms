// https://leetcode.com/problems/2-keys-keyboard/

// Solution 1
class Solution {
public:
    int dp[1010][1010][2];
    
    int solve(int curr, int aux, int n, bool flag) {
        if(curr == n)
            return 0;
        
        if(curr > n)
            return 101010;
        
        if(dp[curr][aux][flag] != -1)
            return dp[curr][aux][flag];
        
        if(flag)
            return dp[curr][aux][flag] = 1 + solve(curr, curr, n, !flag);
        
        return dp[curr][aux][flag] = 1 + min(solve(curr + aux, aux, n, !flag), solve(curr + aux, aux, n, flag));
    }
    
    int minSteps(int n) {
        if(n == 1)
            return 0;
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                for(int k = 0; k < 2; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        
        return solve(1, 1, n, false) + 1;
    }
};

// Solution 2
class Solution {
public:
    int dp[1010][1010];
    
    int solve(int curr, int aux, int n) {
        if(curr == n)
            return 0;
        
        if(curr > n)
            return 101010;
        
        if(dp[curr][aux] != -1)
            return dp[curr][aux];
        
        return dp[curr][aux] = 1 + min(solve(curr + aux, aux, n), 1 + solve(curr + curr, curr, n));
    }
    
    int minSteps(int n) {
        if(n == 1)
            return 0;
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        
        return solve(1, 1, n) + 1;
    }
};