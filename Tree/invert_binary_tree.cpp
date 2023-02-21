// https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;
        
        TreeNode *left = invertTree(root->right);
        TreeNode *right = invertTree(root->left);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
};

// Or
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;

        TreeNode *node = new TreeNode(root->val);
        node->left = invertTree(root->right);
        node->right = invertTree(root->left);

        return node;
    }
};
