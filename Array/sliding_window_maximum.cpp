// https://leetcode.com/problems/sliding-window-maximum/

// Solution 1
class Solution {
public:
    int myMax(vector<int>& nums, int l, int r) {
        int m = INT_MIN;
        
        while(l <= r) {
            m = max(m, nums[l++]);
        }
        
        return m;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)
            return nums;
        
        vector<int> res;
        
        if(!nums.size())
            return res;
        
        int m = INT_MIN;
        for(int i = 0; i < k; i++)
            m = max(m, nums[i]);
        
        res.push_back(m);
        for(int i = k; i < nums.size(); i++)
            res.push_back(myMax(nums, i - k + 1, i));
        
        return res;
    }
};

// Solution 2
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> dp;
        
        if(!nums.size())
            return dp;
        
        dp.push_back(*max_element(nums.begin(), nums.begin()+k));
        for(int i = 1; i <= nums.size()-k; i++) {
            int lastElem = nums[i+k-1];
            if(lastElem >= dp[i-1])
                dp.push_back(lastElem);
            else if(dp[i-1] > lastElem && dp[i-1] > nums[i-1])
                dp.push_back(dp[i-1]);
            else
                dp.push_back(*max_element(nums.begin()+i, nums.begin()+i+k));
        }
        
        return dp;
    }
};

// Solution 3
class Solution {
public:
    int maxIndex(vector<int>& nums, int l, int r) {
        int index = l;
        
        for(int i = l+1; i <= r; i++)
            if(nums[i] > nums[index])
                index = i;
        
        return index;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        
        if(!nums.size())
            return res;
        
        int l = 0;
        int r = k-1;
        int index = maxIndex(nums, l, r);
        while(r < nums.size()) {
            if(nums[r] > nums[index])
                index = r;
            if(l > index)
                index = maxIndex(nums, l, r);
            res.push_back(nums[index]);
            l++;
            r++;
        }
        
        return res;
    }
};