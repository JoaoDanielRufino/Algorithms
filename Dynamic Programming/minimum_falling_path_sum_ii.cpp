// https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

class Solution {
public:
    bool OK(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || x >= grid.size())
            return false;

        if(y < 0 || y >= grid[x].size())
            return false;

        return true;
    }

    int solve(vector<vector<int>>& grid, int x, int y, vector<vector<int>> & dp) {
        if(x == grid.size()-1)
            return grid[x][y];

        if(dp[x][y] != INT_MAX)
            return dp[x][y];

        int ans = INT_MAX;
        for(int i = 0; i < grid[x].size(); i++) {
            if(i != y && OK(grid, x + 1, i))
                ans = min(ans, grid[x][y] + solve(grid, x + 1, i, dp));
        }

        return dp[x][y] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        vector<vector<int>> dp(grid.size(), vector<int> (grid.size(), INT_MAX));

        for(int i = 0; i < grid.size(); i++) {
            ans = min(ans, solve(grid, 0, i, dp));
        }

        return ans;
    }
};

// Or
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int> (n));

        for(int i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int ans = INT_MAX;
                for(int k = 0; k < n; k++) {
                    if(k != j)
                        ans = min(ans, grid[i][j] + dp[i-1][k]);
                }
                dp[i][j] = ans;
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, dp[n-1][i]);
        }

        return ans;
    }
};
