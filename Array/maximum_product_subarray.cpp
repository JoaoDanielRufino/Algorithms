// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal, minVal, res;
        
        maxVal = minVal = res = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0)
                swap(maxVal, minVal);
            
            maxVal = max(nums[i], maxVal * nums[i]);
            minVal = min(nums[i], minVal * nums[i]);
            
            res = max(res, maxVal);
        }
        
        return res;
    }
};

// This solution is slower
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxRes = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            int curr = 1;
            for(int j = i; j < nums.size(); j++) {
                curr *= nums[j];
                maxRes = max(maxRes, curr);
            }
        }
        
        return maxRes;
    }
};
*/