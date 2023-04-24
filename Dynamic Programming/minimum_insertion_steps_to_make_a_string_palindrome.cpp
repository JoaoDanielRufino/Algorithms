// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

class Solution {
public:
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if(i >= s.size() || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j]; 

        if(s[i] == s[j])
            return dp[i][j] = 1 + solve(s, i + 1, j - 1, dp);

        return dp[i][j] = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
    }

    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

        return solve(s, 0, s.size() - 1, dp);
    }
};

// Or
class Solution {
public:
    int lcs(string& s, int i, int j, vector<vector<int>>& dp) {
        if(i >= s.size() || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = 1 + lcs(s, i + 1, j - 1, dp);

        return dp[i][j] = max(lcs(s, i + 1, j, dp), lcs(s, i, j - 1, dp));
    }

    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));

        return s.size() - lcs(s, 0, s.size() - 1, dp);
    }
};
