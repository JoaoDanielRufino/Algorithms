// https://www.interviewbit.com/problems/next-greater-number-bst/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* search(TreeNode *A, int B) {
    if(A->val == B)
        return A;
    
    if(A->val > B)
        return search(A->left, B);
    return search(A->right, B);
}
 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode *res, *parent, *tmp;
    
    res = nullptr;
    tmp = search(A, B);
    
    if(tmp->right) {
        res = tmp->right;
        while(res->left)
            res = res->left;
    }
    else {
        parent = A;
        while(parent != tmp) {
            if(parent->val > B) {
                res = parent;
                parent = parent->left;
            }
            else
                parent = parent->right;
        }
    }
    
    return res;
}
