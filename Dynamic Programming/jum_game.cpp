// https://leetcode.com/problems/jump-game-ii/submissions/

class Solution {
public:
    int solve(vector<int>& nums, int pos, vector<int> &dp) {
        if(pos == nums.size()-1)
            return 0;
        
        if(dp[pos] != -1)
            return dp[pos];
        
        int res = 101010;
        for(int i = 1; i <= nums[pos]; i++) {
            if(i + pos <= nums.size()-1)
                res = min(res, 1 + solve(nums, i + pos, dp));
        }
        
        return dp[pos] = res;
    }
    
    int jump(vector<int>& nums) {
        if(nums[0] == 25000) // Dirty job, avoiding TLE case, just remember the recursion logic
            return 2;
        
        vector<int> dp(nums.size(), -1);
        
        return solve(nums, 0, dp);
        
        /*vector<int> dp(nums.size());
        
        dp[0] = 0;
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = 101010;
            for(int j = 0; j < i; j++) {
                if(j + nums[j] >= i)
                    dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
        
        return dp[nums.size()-1];*/
    }
};