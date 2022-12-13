// https://leetcode.com/problems/minimum-falling-path-sum/description/

class Solution {
public:
    int dx[3] = { 1, 1, 1 };
    int dy[3] = { -1, 0, 1 };

    bool OK(vector<vector<int>>& matrix, int x, int y) {
        if(x < 0 || x >= matrix.size())
            return false;

        if(y < 0 || y >= matrix[x].size())
            return false;

        return true;
    }

    int solve(vector<vector<int>>& matrix, int x, int y, map<pair<int, int>, int>& dp) {
        if(x == matrix.size()-1)
            return matrix[x][y];

        if(dp.count({ x, y }))
            return dp[{ x, y }];

        int ans = INT_MAX;
        for(int i = 0; i < 3; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(OK(matrix, xx, yy)) {
                ans = min(ans, matrix[x][y] + solve(matrix, xx, yy, dp));
                dp[{ x, y }] = ans;
            }
        }

        return dp[{ x, y }] = ans;
    } 

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        map<pair<int, int>, int> dp;

        for(int i = 0; i < matrix.size(); i++) {
            ans = min(ans, solve(matrix, 0, i, dp));
        }

        return ans;
    }
};
