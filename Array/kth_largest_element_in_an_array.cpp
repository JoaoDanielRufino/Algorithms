// https://leetcode.com/problems/kth-largest-element-in-an-array/

// Solution 1
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = 0;
        
        sort(nums.begin(), nums.end());
        
        int i = nums.size()-1;
        while(k) {
            res = nums[i--];
            k--;
        }
        
        return res;
    }
};

// Solution 2
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        
        while(l <= r) {
            int mid = l + (r - l)/2;
            int greater = 0, equal = 0;
            for(int x : nums) {
                if(x > mid)
                    greater++;
                else if(x == mid)
                    equal++;
            }
            if(greater < k && greater + equal >= k)
                return mid;
            else if(greater < k)
                r = mid-1;
            else
                l = mid+1;
        }
        
        return -1;
    }
};