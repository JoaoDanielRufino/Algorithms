// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int> &nums, int l, int r) {
        if(l > r)
            return nullptr;
        
        int mid = (l + r) / 2;
        
        TreeNode *root = new TreeNode(nums[mid]);
        
        root->left = solve(nums, l, mid-1);
        root->right = solve(nums, mid+1, r);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};