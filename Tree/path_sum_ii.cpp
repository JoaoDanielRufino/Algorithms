// https://leetcode.com/problems/path-sum-ii/
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
    vector< vector<int> > res;
    
    void hasSum(TreeNode* root, int sum, int currentSum, vector<int> current) {
        if(!root)
            return;
        
        if(!root->left && !root->right) {
            if(currentSum + root->val == sum) {
                current.push_back(root->val);
                res.push_back(current);
            }
            return;
        }
        
        current.push_back(root->val);
        hasSum(root->left, sum, currentSum + root->val, current);
        hasSum(root->right, sum, currentSum + root->val, current);
        current.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> current;
        
        hasSum(root, sum, 0, current);
        
        return res;
    }
};
