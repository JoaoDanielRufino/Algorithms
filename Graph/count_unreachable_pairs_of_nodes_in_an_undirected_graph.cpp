// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

class Solution {
public:
    int dfs(vector<vector<int>>& graph, int curr, vector<bool>& seen) {
        seen[curr] = true;

        int nodes = 1;
        for(int adj : graph[curr]) {
            if(!seen[adj]) {
                nodes += dfs(graph, adj, seen);
            }
        }

        return nodes;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for(vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        long long ans = 0, componentSize = 0, remaining = n;
        vector<bool> seen(n);
        for(int i = 0; i < n; i++) {
            if(!seen[i]) {
                componentSize = dfs(graph, i, seen);
                ans += componentSize * (remaining- componentSize);
                remaining -= componentSize;
            }
        }

        return ans;
    }
};
