// https://leetcode.com/problems/path-sum-iii/

// Solution 1
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
    
    void solve(TreeNode* root, int sum) {
        if(!root)
            return;
        
        if(root->val == sum)
            res++;
        
        solve(root->left, sum - root->val);
        solve(root->right, sum - root->val);
    }
    
    void helper(TreeNode* root, int sum) {
        if(!root)
            return;
        
        solve(root, sum);
        helper(root->left, sum);
        helper(root->right, sum);
    }
    
    int pathSum(TreeNode* root, int sum) {
        res = 0;
        
        helper(root, sum);
        
        return res;
    }
};

// Solution 2
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
    int solve(TreeNode* root, int sum) {
        if(!root)
            return 0;
        
        int res = 0;
        if(root->val == sum)
            res++;
        
        return res + solve(root->left, sum - root->val) + solve(root->right, sum - root->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        
        return solve(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};