// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    
    void solve(TreeNode* root, int minVal, int maxVal) {
        if(!root)
            return;
        
        if(minVal != INT_MAX)
            res = max(res, abs(root->val - minVal));
        if(maxVal != INT_MIN)
            res = max(res, abs(root->val - maxVal));
        
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        
        solve(root->left, minVal, maxVal);
        solve(root->right, minVal, maxVal);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        res = INT_MIN;
        
        solve(root, INT_MAX, INT_MIN);
        
        return res;
    }
};