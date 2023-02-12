// https://leetcode.com/problems/as-far-from-land-as-possible/description/

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool OK(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& seen) {
        if(i < 0 || i >= grid.size())
            return false;

        if(j < 0 || j >= grid[i].size())
            return false;

        return !seen[i][j];
    }

    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<bool>> seen(grid.size(), vector<bool> (grid[0].size()));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j]) {
                    q.push({i, j});
                    seen[i][j] = true;
                }
            }
        }

        int ans = -1;
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                pair<int, int> node = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int x = node.first + dx[i];
                    int y = node.second + dy[i];
                    if(OK(grid, x, y, seen)) {
                        q.push({x, y});
                        seen[x][y] = true;
                    }
                }
            }

            ans++;
        }

        return !ans ? -1 : ans;
    }
};
