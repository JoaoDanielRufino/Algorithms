// https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    vector<int> dp;
    
    int solve(vector<int>& nums, int index) {
        if(index >= nums.size())
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        int sum = 0;
        int i = index;
        while(i < nums.size() && nums[index] == nums[i]) {
            sum += nums[i];
            i++;
        }
        
        while(i < nums.size() && nums[i] == nums[index] + 1)
            i++;
        
        return dp[index] = max(sum + solve(nums, i), solve(nums, index+1));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        dp.assign(nums.size(), -1);
        
        return solve(nums, 0);
    }
};