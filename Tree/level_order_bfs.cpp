// https://www.interviewbit.com/problems/level-order/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector< vector<int> > res;
    queue<TreeNode*> q;
    
    q.push(A);
    while(!q.empty()) {
        vector<int> aux;
        int size = q.size();
        while(size--) {
            TreeNode *node = q.front();
            q.pop();
            
            aux.push_back(node->val);
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        res.push_back(aux);
    }
    
    return res;
}
