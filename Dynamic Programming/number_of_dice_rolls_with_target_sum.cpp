class Solution {
public:
    int modulo = 1000000007;
    int dp[31][1005];
    
    int solve(int d, int f, int target) {
        if(!d && !target)
            return 1;
        
        if(target < 0 || !d)
            return 0;
        
        if(dp[d][target] != -1)
            return dp[d][target];
        
        int res = 0;
        for(int i = 1; i <= f; i++) {
            res = (res + solve(d-1, f, target - i)) % modulo;
        }
        
        return dp[d][target] = res;
    }
    
    int numRollsToTarget(int d, int f, int target) {
        for(int i = 0; i < 31; i++) {
            for(int j = 0; j < 1005; j++) {
                dp[i][j] = -1;
            }
        }
        
        return solve(d, f, target);
    }
};
