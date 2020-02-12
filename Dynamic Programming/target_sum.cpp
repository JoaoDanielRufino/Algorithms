// https://leetcode.com/problems/target-sum/

class Solution {
public:
    int dp[22][2010];
    
    int solve(vector<int>& nums, int S, int sum, int i) {
        if(i == nums.size()) {
            if(S == sum)
                return 1;
            else
                return 0;
        }
        
        if(dp[i][sum + 1000] != -1) // Adding 1000 to prevent negative numbers
            return dp[i][sum + 1000];
        
        return dp[i][sum + 1000] = solve(nums, S, sum + nums[i], i+1) + solve(nums, S, sum - nums[i], i+1);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        memset(dp, -1, sizeof(dp));
        
        return solve(nums, S, 0, 0);
    }
};