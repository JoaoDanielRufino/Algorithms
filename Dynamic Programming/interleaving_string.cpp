// https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    int dp[110][110];
    
    bool solve(string s1, string s2, string s3, int i, int j, int k) {
        if(k >= s3.size()) {
            if(i >= s1.size() && j >= s2.size())
                return true;
            return false;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = (s1[i] == s3[k] && solve(s1, s2, s3, i+1, j, k+1)) || (s2[j] == s3[k] && solve(s1, s2, s3, i, j+1, k+1));
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        for(int i = 0; i <= s1.size(); i++) {
            for(int j = 0; j <= s2.size(); j++) {
                dp[i][j] = -1;
            }
        }
        
        return solve(s1, s2, s3, 0, 0, 0);
    }
};