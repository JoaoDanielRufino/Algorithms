// https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector< vector<int> > res;
    
    void solve(vector<int>& nums, vector<int> curr, int start) {
        res.push_back(curr);
        
        for(int i = start; i < nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1])
                continue;
            
            curr.push_back(nums[i]);
            solve(nums, curr, i+1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        solve(nums, vector<int>(), 0);
        
        return res;
    }
};