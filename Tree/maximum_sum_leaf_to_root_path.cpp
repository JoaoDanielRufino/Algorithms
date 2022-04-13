// https://practice.geeksforgeeks.org/problems/maximum-sum-leaf-to-root-path/1#

class Solution{
    public:
    int ans = INT_MIN;
    
    void solve(Node* root, int currSum) {
        if(!root)
            return;
            
        if(!root->left && !root->right) {
            ans = max(ans, currSum + root->data);
            return;
        }
        
        if(root->left)
            solve(root->left, currSum + root->data);
        if(root->right)
            solve(root->right, currSum + root->data);
    }
    
    int maxPathSum(Node* root)
    {
        solve(root, 0);
        
        return ans;
    }
};
