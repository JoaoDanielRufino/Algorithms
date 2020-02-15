// https://leetcode.com/problems/sliding-window-median/

class Solution {
public:
    int lowerBound(vector<long long int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(nums[mid] >= target)
                r = mid-1;
            else
                l = mid+1;
        }
        
        return l;
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r;
        vector<long long int> aux;
        vector<double> res;

        for(int i = 0; i < k; i++) {
            if(aux.empty())
                aux.push_back(nums[i]);
            else
                aux.insert(aux.begin() + lowerBound(aux, nums[i]), nums[i]);
        }
        
        int mid = aux.size() / 2;
        r = k-1;
        while(r < nums.size()) {
            if(k & 1) {
                res.push_back(aux[mid]);
            }
            else {
                res.push_back((aux[mid-1] + aux[mid])/2.0);
            }
            aux.erase(aux.begin() + lowerBound(aux, nums[l]));
            l++;
            r++;
            if(r < nums.size())
                aux.insert(aux.begin() + lowerBound(aux, nums[r]), nums[r]);
        }
        
        return res;
    }
};