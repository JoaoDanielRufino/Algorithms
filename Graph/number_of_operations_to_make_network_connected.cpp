// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Solution {
public:
    void dfs(vector<vector<int>>& graph, int current, vector<bool>& seen) {
        seen[current] = true;

        for(int adj : graph[current]) {
            if(!seen[adj])
                dfs(graph, adj, seen);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;

        vector<vector<int>> graph(n);

        for(vector<int> connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }

        int ans = 0;
        vector<bool> seen(n);
        for(int i = 0; i < n; i++) {
            if(!seen[i]) {
                dfs(graph, i, seen);
                ans++;
            }
        }

        return ans - 1;
    }
};
