// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l, r, mid, res;
        
        l = 0; r = nums.size()-1;
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(!mid || nums[mid] > nums[mid-1]) {
                res = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        
        return res;
    }
};