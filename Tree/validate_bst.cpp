// https://leetcode.com/problems/validate-binary-search-tree/
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
    vector<int> vet;
    
    void inOrder(TreeNode* root) {
        if(!root)
            return;
        
        if(root->left)
            inOrder(root->left);
        vet.push_back(root->val);
        if(root->right)
            inOrder(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        inOrder(root);
        
        for(int i = 0; i < vet.size()-1; i++) {
            if(vet[i] >= vet[i+1])
                return false;
        }
        
        return true;
    }
};