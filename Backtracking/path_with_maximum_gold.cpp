// https://leetcode.com/problems/path-with-maximum-gold/

// Solution 1
class Solution {
public:
    int dx[4] = { 1, -1, 0, 0};
    int dy[4] = { 0, 0, 1, -1};
    
    bool OK(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size())
            return false;
        
        if(!grid[i][j])
            return false;
        
        return true;
    }
    
    int solve(vector<vector<int>>& grid, int x, int y) {        
        int aux = grid[x][y];
        grid[x][y] = 0;
        int res = 0;
        for(int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(OK(grid, nextX, nextY)) {
                res = max(res, grid[nextX][nextY] + solve(grid, nextX, nextY));
            }
        }
        grid[x][y] = aux;
        return res;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j])
                    res = max(res, grid[i][j] + solve(grid, i, j));
            }
        }
        
        return res;
    }
};

// Solution 2
class Solution {
public:
    int dx[4] = { 1, -1, 0, 0};
    int dy[4] = { 0, 0, 1, -1};
    int res = 0;
    
    bool OK(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size())
            return false;
        
        if(!grid[i][j])
            return false;
        
        return true;
    }
    
    void solve(vector<vector<int>>& grid, int x, int y, int sum) {
        res = max(res, sum);
        
        int aux = grid[x][y];
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(OK(grid, nextX, nextY)) {
                solve(grid, nextX, nextY, sum + grid[nextX][nextY]);
            }
        }
        grid[x][y] = aux;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j])
                    solve(grid, i, j, grid[i][j]);
            }
        }
        
        return res;
    }
};