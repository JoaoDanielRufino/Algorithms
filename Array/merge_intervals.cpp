// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        int last = -1;
        for(vector<int> interval : intervals) {
            if(last == -1 || ans[last][1] < interval[0]) {
                ans.push_back(interval);
                last++;
            } else {
                ans[last][1] = max(ans[last][1], interval[1]);
            }
        }

        return ans;
    }
};
