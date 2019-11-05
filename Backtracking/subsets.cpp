// https://leetcode.com/problems/subsets/submissions/

class Solution {
public:
    vector< vector<int> > res;
    
    void solve(vector<int> nums, vector<int> curr, int start) {
        res.push_back(curr);
        
        for(int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            solve(nums, curr, i+1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, vector<int> (), 0);
        
        return res;
    }
};