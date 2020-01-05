// https://leetcode.com/problems/subtree-of-another-tree/

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
    bool helper(TreeNode* s, TreeNode* t) {
        if(!s && !t)
            return true;
        
        if(!s || !t)
            return false;
        
        return s->val == t->val && helper(s->left, t->left) && helper(s->right, t->right);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s)
            return false;
        
        return helper(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};