// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<vector<int>> dp;
    
    bool ok(int i, int j, vector<vector<int>>& matrix) {
        if(i < 0 || i >= matrix.size())
            return false;
        
        if(j < 0 || j >= matrix[i].size())
            return false;
        
        return true;
    }
    
    int solve(int i, int j, vector<vector<int>>& matrix) {
        if(!ok(i, j, matrix))
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res = 1;
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(ok(x, y, matrix) && matrix[x][y] > matrix[i][j]) {
                res = max(res, 1 + solve(x, y, matrix));
            }
        }
        
        return dp[i][j] = res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.assign(matrix.size(), vector<int> (matrix[0].size(), -1));
        
        int res = 1;
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(dp[i][j] == -1)
                    dp[i][j] = solve(i, j, matrix);
                res = max(res, dp[i][j]);
            }
        }
        
        return res;
    }
};
