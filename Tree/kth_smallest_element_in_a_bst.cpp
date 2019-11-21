// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    
    void solve(TreeNode *root, int& k) {
        if(!root)
            return;
        
        solve(root->left, k);
        
        k--;
        
        if(!k) {
            res = root->val;
            return;
        }
        
        solve(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        solve(root, k);
        
        return res;
    }
};