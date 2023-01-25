// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<bool> seen(n);

        for(vector<int> edge : edges) {
            seen[edge[1]] = true;
        }

        for(int i = 0; i < n; i++) {
            if(!seen[i])
                ans.push_back(i);
        }

        return ans;
    }
};
