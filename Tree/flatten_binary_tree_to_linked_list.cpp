// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        TreeNode *prev = nullptr;
        stack<TreeNode*> st;
        
        st.push(root);
        while(!st.empty()) {
            TreeNode *tmp = st.top();
            st.pop();
            
            if(tmp->right)
                st.push(tmp->right);
            if(tmp->left)
                st.push(tmp->left);
            
            if(prev) {
                prev->left = nullptr;
                prev->right = tmp;
            }
            prev = tmp;
        }
    }
};

// Or this
class Solution {
public:
    vector<TreeNode*> aux;
    
    void preorder(TreeNode* root) {
        if(!root)
            return;
        
        aux.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }
    
    void flatten(TreeNode* root) {
        preorder(root);
        
        TreeNode *curr = root;
        for(int i = 1; i < aux.size(); i++) {
            curr->left = nullptr;
            curr->right = aux[i];
            curr = curr->right;
        }
    }
};
