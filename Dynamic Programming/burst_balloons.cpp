// https://leetcode.com/problems/burst-balloons/description/

class Solution {
public:
    int solve(vector<int>& nums, int left, int right, vector<vector<int>>& dp) {
        if(left > right)
            return 0;

        if(left == right)
            return nums[left-1] * nums[left] * nums[right+1];

        if(dp[left][right] != -1)
            return dp[left][right];

        int ans = INT_MIN;
        for(int i = left; i <= right; i++) {
            int burst = nums[left-1] * nums[i] * nums[right+1];
            ans = max(ans, burst + solve(nums, left, i - 1, dp) + solve(nums, i + 1, right, dp));
        }

        return dp[left][right] = ans;
    }

    int maxCoins(vector<int>& nums) {
        vector<int> aux;

        aux.push_back(1);
        for(int x : nums) 
            aux.push_back(x);
        aux.push_back(1);

        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1, -1));

        return solve(aux, 1, aux.size() - 2, dp);
    }
};
