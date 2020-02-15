// https://leetcode.com/problems/continuous-subarray-sum/

// Solution 1
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0, size = 0;
            for(int j = i; j < nums.size(); j++) {
                sum += nums[j];
                size++;
                if(size >= 2) {
                    if(!k && !sum)
                        return true;
                    else if(k && !(sum % k))
                        return true;
                }
            }
        }
        
        return false;
    }
};

// Solution 2
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> hash;
        int sum = 0;
        
        hash[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if(k)
                sum = sum % k;
            
            if(hash.count(sum)) {
                if(i - hash[sum] >= 2)
                    return true;
            }
            else
                hash[sum] = i;
        }
        
        return false;
    }
};