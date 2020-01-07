// https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> res;
        
        if(start > end) {
            res.push_back(nullptr);
            return res;
        }
        
        for(int i = start; i <= end; i++) {
            vector<TreeNode*> left = solve(start, i-1);
            vector<TreeNode*> right = solve(i+1, end);
            for(int j = 0; j < left.size(); j++) {
                for(int k = 0; k < right.size(); k++) {
                    TreeNode *node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    res.push_back(node);
                }
            }
        }
        
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(!n)
            return vector<TreeNode*>();
        
        return solve(1, n);
    }
};