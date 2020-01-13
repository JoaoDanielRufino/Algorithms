// https://leetcode.com/problems/subarray-sum-equals-k/

// Solution 1
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if(sum == k)
                    count++;
            }
        }
        
        return count;
    }
};

// Solution 2
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int sum = 0;
        int count = 0;
        
        hash[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if(hash.count(sum - k))
                count += hash[sum-k];
            
            hash[sum]++;
        }
        
        return count;
    }
};