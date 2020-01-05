// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow, fast;
        
        slow = fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        int a = nums[0];
        int b = slow;
        while(a != b) {
            a = nums[a];
            b = nums[b];
        }
        
        return a;
    }
};