// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        
        int l, r, mid, low = -1;
        
        l = 0; r = nums.size()-1;
        while(l <= r) {               // Lower bound
            mid = l + (r - l) /2;
            if(nums[mid] == target) {
                low = mid;
                r = mid-1;
            }
            else if(nums[mid] > target)
                r = mid-1;
            else
                l = mid+1;
        }
        res.push_back(low);
        
        int up = -1;
        l = 0; r = nums.size()-1;
        while(l <= r) {               // Upper bound
            mid = l + (r - l) /2;
            if(nums[mid] == target) {
                up = mid;
                l = mid+1;
            }
            else if(nums[mid] > target)
                r = mid-1;
            else
                l = mid+1;
        }
        res.push_back(up);
        
        return res;
    }
};