// https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        
        for(int i = 0; i < nums.size(); i++) {
            if(hash.count(nums[i]) && i - hash[nums[i]] <= k)
                return true;
            else
                hash[nums[i]] = i;
        }
        
        return false;
    }
};