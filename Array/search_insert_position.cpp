// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid;
        
        while(l <= r) { // Lower Bound
            mid = l + (r - l) / 2;
            if(nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return l;
    }
};