// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minSize = INT_MAX, sum = 0, l = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while(sum >= s) {
                minSize = min(minSize, i + 1 - l);
                sum -= nums[l++];
            }
        }
        
        return minSize == INT_MAX ? 0 : minSize;
    }
};