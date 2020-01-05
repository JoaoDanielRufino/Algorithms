// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// https://www.youtube.com/watch?v=CTBEcmzLAuA&feature=youtu.be

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int tmp = abs(nums[i]);
            nums[tmp - 1] = abs(nums[tmp - 1]) * -1;
        }
        
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 1)
                res.push_back(i+1);
        }
        
        return res;
    }
};