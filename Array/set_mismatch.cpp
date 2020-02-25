// https://leetcode.com/problems/set-mismatch/

// Solution 1
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        int sum = 0;
        unordered_set<int> hash;
        
        for(int n : nums) {
            if(hash.count(n))
                res.push_back(n);
            else {
                hash.insert(n);
                sum += n;
            }
        }
        
        int total = (nums.size() * (nums.size() + 1)) / 2;
        res.push_back(total - sum);
        
        return res;
    }
};

//Solution 2
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        
        for(int n : nums) {
            if(nums[abs(n)-1] < 0)
                res.push_back(abs(n));
            else
                nums[abs(n)-1] *= -1;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                res.push_back(i+1);
                break;
            }
        }
        
        return res;
    }
};