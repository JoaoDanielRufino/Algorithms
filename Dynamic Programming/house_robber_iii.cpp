// https://leetcode.com/problems/house-robber-iii/

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
    map< pair<TreeNode*, bool>, int> dp;
    
    int solve(TreeNode* root, bool OK) {
        if(!root)
            return 0;
        
        if(dp.count({root, OK}))
            return dp[{root, OK}];
        
        if(OK) {
            return dp[{root, OK}] = root->val + solve(root->left, false) + solve(root->right, false);
        }
        
        int left = max(solve(root->left, true), solve(root->left, false));
        int right = max(solve(root->right, true), solve(root->right, false));
        return dp[{root, OK}] = left + right;
    }
    
    int rob(TreeNode* root) {
        return max(solve(root, true), solve(root, false));
    }
};