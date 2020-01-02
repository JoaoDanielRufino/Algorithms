// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool solve(vector<int>& nums, int i, int sum, vector< vector<int> >& dp) {
        if(!sum)
            return true;
        
        if(i >= nums.size() && sum != 0)
            return false;
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        if(nums[i] > sum)
            return dp[i][sum] = solve(nums, i + 1, sum, dp);
        
        return dp[i][sum] = solve(nums, i + 1, sum, dp) || solve(nums, i + 1, sum - nums[i], dp);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        
        if(sum & 1)
            return false;
        
        vector< vector<int> > dp(nums.size(), vector<int>((sum / 2)+1, -1));
        
        return solve(nums, 0, sum / 2, dp);
    }
};