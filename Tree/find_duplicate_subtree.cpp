// https://leetcode.com/problems/find-duplicate-subtrees/

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
    vector<TreeNode*> res;
    unordered_map<string, int> hash;
    
    string preorder(TreeNode* t) {
        if(!t)
            return "";
        
        string id = to_string(t->val) + "," + preorder(t->left) + "," + preorder(t->right);
        
        hash[id]++;
        if(hash[id] == 2)
            res.push_back(t);
        
        return id;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        
        return res;
    }
};