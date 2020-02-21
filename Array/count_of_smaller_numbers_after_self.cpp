// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
public:
    int binarySearch(vector<int>& vet, int target) { // Lower Bound
        int l = 0, r = vet.size()-1, mid;
        
        while(l <= r) {
            mid = l + (r - l) / 2;
            if(vet[mid] >= target)
                r = mid-1;
            else
                l = mid+1;
        }
        
        return l;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> sorted;
        
        for(int i = nums.size()-1; i >= 0; i--) {
            int index = binarySearch(sorted, nums[i]); // Inserted sort position
            res[i] = index;
            sorted.insert(sorted.begin() + index, nums[i]);
        }
        
        return res;
    }
};