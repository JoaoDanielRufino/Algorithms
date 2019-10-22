// https://leetcode.com/problems/wildcard-matching/

class Solution {
public: 
    bool isMatch(string s, string p) {
        bool dp[s.size()+1][p.size()+1];
        
        memset(dp, false, sizeof(dp));
        
        dp[0][0] = true;
        for(int i = 1; i <= p.size(); i++) {
            if(p[i-1] == '*')
                dp[0][i] = dp[0][i-1];
        }
        
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 1; j <= p.size(); j++) {
                if(p[j-1] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                else if(s[i-1] == p[j-1] || p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = false;
            }
        }
        
        return dp[s.size()][p.size()];
    }
};