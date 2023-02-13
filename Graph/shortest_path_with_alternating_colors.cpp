// https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> graph(n); // {node, color}
        vector<int> ans(n, -1);

        for(vector<int> red : redEdges) {
            graph[red[0]].push_back({red[1], 0});
        }

        for(vector<int> blue : blueEdges) {
            graph[blue[0]].push_back({blue[1], 1});
        }

        queue<pair<int, pair<int, int>>> q; // {color, {node, distance}}
        vector<vector<bool>> seen(n, vector<bool> (2));

        ans[0] = 0;
        q.push({-1, {0, 0}});
        seen[0][0] = seen[0][1] = true;
        while(!q.empty()) {
            pair<int, pair<int, int>> node = q.front();
            q.pop();

            for(auto [adj, color] : graph[node.second.first]) {
                if(!seen[adj][color] && color != node.first) {
                    q.push({color, {adj, node.second.second + 1}});
                    seen[adj][color] = true;
                    if(ans[adj] == -1)
                        ans[adj] = node.second.second + 1;
                }
            }
        }

        return ans;
    }
};
