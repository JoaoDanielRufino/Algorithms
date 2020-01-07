// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:  
    int findLength(vector<int>& A, vector<int>& B) {
        int maxLen = 0;
        vector< vector<int> > dp(A.size()+1, vector<int>(B.size()+1, 0));
        
        for(int i = 1; i <= A.size(); i++) {
            for(int j = 1; j <= B.size(); j++) {
                if(A[i-1] == B[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        
        return maxLen;
    }
};