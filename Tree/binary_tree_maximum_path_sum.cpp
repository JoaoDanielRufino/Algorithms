// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int res;
    
    int solve(TreeNode* root) {
        if(!root)
            return 0;
        
        int left = max(solve(root->left), 0);
        int right = max(solve(root->right), 0);
        
        res = max(res, root->val + left + right);
        
        return max(root->val + left, root->val + right);
    }
    
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        
        solve(root);
        
        return res;
    }
};