// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// https://www.youtube.com/watch?v=13m9ZCB8gjw

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        
        if(root == p || root == q)
            return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right)
            return root;
        
        return left ? left : right;
    }
};

// Solution 2
class Solution {
public:
    TreeNode *res;
    
    bool solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return false;
        
        int left = solve(root->left, p, q) ? 1 : 0;
        int right = solve(root->right, p, q) ? 1 : 0;
        int mid = root == p || root == q;
        
        if(mid + left + right >= 2)
            res = root;
        
        return mid + left + right > 0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        return res;
    }
};