// https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/

class Solution {
public:
    int solve(vector<int>& prefixSum, int target) {
        int left = 0, right = prefixSum.size() - 1;

        int ans = -1;
        while(left <= right) {
            int mid = (right + left) / 2;

            if(prefixSum[mid] == target)
                return mid;
            if(prefixSum[mid] > target)
                right = mid - 1;
            else {
                left = mid + 1;
                ans = mid;
            }
        }

        return ans;
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> prefixSum;

        sort(nums.begin(), nums.end());

        prefixSum.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            prefixSum.push_back(nums[i] + prefixSum[i-1]);
        }

        vector<int> ans;
        for(int query : queries) {
            ans.push_back(solve(prefixSum, query) + 1);
        }

        return ans;
    }
};
