// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l < r) {
            int mid = l + (r - l)/2;

            if(mid % 2 == 0 && nums[mid] == nums[mid + 1]) {
                l = mid + 1;
            } else if(mid % 2 == 1 && nums[mid] == nums[mid - 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};
