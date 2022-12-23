// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution {
public:
    int solve(vector<int>& price, int i, bool buy, vector<vector<int>>& dp) {
        if(i >= price.size())
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];

        if(buy)
            return dp[i][buy] = max(solve(price, i + 1, false, dp) - price[i], solve(price, i + 1, true, dp));
            
        return dp[i][buy] = max(price[i] + solve(price, i + 2, true, dp), solve(price, i + 1, false, dp));
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));

        return solve(prices, 0, true, dp);
    }
};
