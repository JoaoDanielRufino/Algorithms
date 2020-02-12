// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    static bool myCompare(const vector<int> a, const vector<int> b) {
        if(a[0] < b[0])
            return true;
        if(a[0] == b[0] && a[1] < b[1])
            return true;
        return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(!intervals.size() || intervals.size() == 1)
            return intervals;
        
        vector< vector<int> > res;
        
        sort(intervals.begin(), intervals.end(), myCompare);
        
        int lastElem = -1;
        for(auto interval : intervals) {
            if(lastElem == -1 || res[lastElem][1] < interval[0]) {
                res.push_back(interval);
                lastElem++;
            }
            else
                res[lastElem][1] = max(res[lastElem][1], interval[1]);
        }
        
        return res;
    }
};