// https://leetcode.com/problems/decode-ways/

class Solution {
public:
    // Top-Down
    int solve(string s, int i, vector<int> &dp) {
        if(i >= s.size())
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        int count = 0;
        
        if(s[i] > '0') // One digit
            count = solve(s, i + 1, dp);
        
        if(i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) // Two digits
            count += solve(s, i + 2, dp);
        
        return dp[i] = count;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        
        return solve(s, 0, dp);
        
        // Bottom-Up
        /*if(s[0] == '0')
            return 0;
        
        vector<int> dp(s.size()+1, 0);
        
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= s.size(); i++) {
            if(s[i-1] > '0')
                dp[i] = dp[i-1];
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))
                dp[i] += dp[i-2];
        }
        
        return dp[s.size()];*/
    }
};