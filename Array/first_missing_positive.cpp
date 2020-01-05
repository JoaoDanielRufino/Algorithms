// https://leetcode.com/problems/first-missing-positive/
// this video helps // https://www.youtube.com/watch?v=CTBEcmzLAuA&feature=youtu.be

// O(n) time and O(1) space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int positive = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0)
                positive = nums[i];
        }
        
        if(positive == -1)
            return 1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0)
                nums[i] = positive;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            int tmp = abs(nums[i]);
            if(tmp - 1 < nums.size())
                nums[tmp - 1] = abs(nums[tmp - 1]) * -1;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0)
                return i + 1;
        }
        
        return nums.size() + 1;
    }
};

// O(nlogn) time and O(n) space
/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(!nums.size())
            return 1;
        
        int maxNum = INT_MIN;
        set<int> st;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0)
                st.insert(nums[i]);
            maxNum = max(maxNum, nums[i]);
        }
        
        int res = -1;
        for(int i = 1; i <= maxNum; i++) {
            if(!st.count(i)) {
                res = i;
                break;
            }
        }
        
        if(res == -1)
            return maxNum <= 0 ? 1 : maxNum + 1;
        return res;
    }
};
*/