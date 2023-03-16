// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    unordered_map<int,int> mp;
    
    TreeNode* solve(vector<int>& postorder, int l, int r, int& index) {
        if(l > r || index < 0)
            return nullptr;
        
        TreeNode *node = new TreeNode(postorder[index--]);
        
        int pos = mp[node->val];
        
        node->right = solve(postorder, pos + 1, r, index);
        node->left = solve(postorder, l, pos - 1, index);
                
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        
        int index = postorder.size()-1;
        return solve(postorder, 0, inorder.size()-1, index);
    }
};
