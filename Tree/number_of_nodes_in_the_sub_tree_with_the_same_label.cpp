class Solution {
public:
    vector<int> solve(vector<vector<int>>& graph, int current, int parent, string& labels, vector<int>& ans) {
        vector<int> hash(26);

        if(!graph[current].size()) {
            hash[labels[current] - 'a']++;
            ans[current] = 1;
            return hash;
        }

        for(int adj : graph[current]) {
            if(adj != parent) {
                vector<int> subAns = solve(graph, adj, current, labels, ans);
                for(int i = 0; i < hash.size(); i++) {
                    hash[i] += subAns[i];
                }
            }
        }

        hash[labels[current] - 'a']++;
        ans[current] = hash[labels[current] - 'a'];

        return hash;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n);
        vector<vector<int>> graph(n);

        for(vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        solve(graph, 0, -1, labels, ans);

        return ans;
    }
};
