// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, zero = 0, start = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(!nums[i])
                zero++;

            while(zero > 1) {
                if(!nums[start])
                    zero--;
                start++;
            }

            ans = max(ans, i - start);
        }

        return ans;
    }
};
