// https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    int dp[1000][1000];
    
    bool solve(string s, string p, int i, int j) {
        if(j == p.size()) {
            return i == s.size();
        }
        
        if(j > p.size() || i > s.size())
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        bool ok = false;
        if(s[i] == p[j] || p[j] == '.')
            ok = true;
        
        if(j < p.size()-1 && p[j+1] == '*')
            return dp[i][j] = solve(s, p, i, j+2) || (ok && solve(s, p, i+1, j));
        
        return dp[i][j] = ok && solve(s, p, i+1, j+1);
    }
    
    bool isMatch(string s, string p) {
        for(int i = 0; i <= s.size(); i++) {
            for(int j = 0; j <= p.size(); j++) {
                dp[i][j] = -1;
            }
        }
        
        return solve(s, p, 0, 0);
    }
};