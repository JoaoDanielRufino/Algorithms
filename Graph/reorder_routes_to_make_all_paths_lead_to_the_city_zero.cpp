// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/

class Solution {
public:
    void solve(vector<vector<int>>& graph, int curr, set<vector<int>>& st, vector<bool>& seen, int& ans) {
        seen[curr] = true;

        for(int adj : graph[curr]) {
            if(!seen[adj]) {
                if(!st.count({ adj, curr })) {
                    ans++;
                    st.insert({ adj, curr });
                }
                solve(graph, adj, st, seen, ans);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        set<vector<int>> st;

        for(vector<int> connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
            st.insert(connection);
        }

        int ans = 0;
        vector<bool> seen(n);
        solve(graph, 0, st, seen, ans);

        return ans;
    }
};
