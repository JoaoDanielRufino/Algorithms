// https://leetcode.com/problems/similar-string-groups/description/

class Solution {
public:
    void dfs(vector<vector<int>>& graph, int current, vector<bool>& seen) {
        seen[current] = true;

        for(int adj : graph[current]) {
            if(!seen[adj])
                dfs(graph, adj, seen);
        }
    }

    bool similar(string& a, string& b) {
        int diff = 0;

        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i])
                diff++;
        }

        return !diff || diff == 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        vector<vector<int>> graph(strs.size());

        for(int i = 0; i < strs.size(); i++) {
            for(int j = i + 1; j < strs.size(); j++) {
                if(similar(strs[i], strs[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int ans = 0;
        vector<bool> seen(graph.size());
        for(int i = 0; i < graph.size(); i++) {
            if(!seen[i]) {
                dfs(graph, i, seen);
                ans++;
            }
        }

        return ans;
    }
};
