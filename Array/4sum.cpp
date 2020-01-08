// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> res;
    
    void threeSum(vector<int>& A, int target, int start) {
        for(int i = start; i < A.size()-2; i++) {
            if(i > start && A[i] == A[i-1])
                continue;
            
            int l = i+1;
            int r = A.size()-1;
            while(l < r) {
                int sum = A[i] + A[l] + A[r];
                if(sum == target) {
                    res.push_back({ A[start-1], A[i], A[l], A[r] });
                    int lastLeft = A[l];
                    int lastRight = A[r];
                    while(l < r && lastLeft == A[l])
                        l++;
                    while(l < r && lastRight == A[r])
                        r--;
                }
                else if(sum > target)
                    r--;
                else
                    l++;
            }
        }
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4)
            return res;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()-3; i++) {
            if(!i || nums[i] != nums[i-1])
                threeSum(nums, target - nums[i], i+1);
        }
        
        return res;
    }
};