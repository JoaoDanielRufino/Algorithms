// https://leetcode.com/problems/delete-node-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findMin(TreeNode* root) {
        TreeNode* curr = root;
        
        while(curr->left) {
            curr = curr->left;
        }
        
        return curr;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        
        if(key < root->val)
            root->left = deleteNode(root->left, key);     
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        
        else {
            if(!root->left && !root->right)
                return nullptr;
            
            if(!root->left) {
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            
            if(!root->right) {
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            
            TreeNode* tmp = findMin(root->right);
            root->val = tmp->val;
            root->right = deleteNode(root->right, root->val);
        }
        
        return root;
    }
};
