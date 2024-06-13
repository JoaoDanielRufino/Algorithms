// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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
    void traverse(TreeNode* root, vector<int>& arr) {
        if(!root)
            return;

        traverse(root->left, arr);
        arr.push_back(root->val);
        traverse(root->right, arr);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> aux;

        traverse(root, aux);

        int ans = INT_MAX;
        for(int i = 0; i < aux.size() - 1; i++) {
            ans = min(ans, aux[i+1] - aux[i]);
        }

        return ans;      
    }
};

// recursive
class Solution {
public:
    void traverse(TreeNode* root, int *prev, int *minDiff) {
        if(!root)
            return;

        traverse(root->left, prev, minDiff);

        if (*prev != INT_MIN) {
            *minDiff = min(*minDiff, root->val - *prev);
        }

        *prev = root->val;

        traverse(root->right, prev, minDiff);
    }

    int getMinimumDifference(TreeNode* root) {
        int prev = INT_MIN, minDiff = INT_MAX;

        traverse(root, &prev, &minDiff);

        return minDiff;
    }
};
