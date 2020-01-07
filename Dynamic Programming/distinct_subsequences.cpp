// https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    // Top-Down
    int solve(string s, string t, int i, int j, vector< vector<int> >& dp) {
        if(j >= t.size())
            return 1;
        
        if(i >= s.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j])
            return dp[i][j] = solve(s, t, i+1, j+1, dp) + solve(s, t, i+1, j, dp);
        
        return dp[i][j] = solve(s, t, i+1, j, dp);
    }
    
    int numDistinct(string s, string t) {
        /*vector< vector<int> > dp(s.size(), vector<int>(t.size(), -1));
        
        return solve(s, t, 0, 0, dp);*/
        
        // Bottom-Up
        vector< vector<long long int> > dp(t.size()+1, vector<long long int>(s.size()+1));
        
        for(int j = 0; j <= s.size(); j++)
            dp[0][j] = 1;
        
        for(int i = 1; i <= t.size(); i++) {
            dp[i][0] = 0;
            for(int j = 1; j <= s.size(); j++) {
                if(s[j-1] == t[i-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        
        return dp[t.size()][s.size()];
    }
};