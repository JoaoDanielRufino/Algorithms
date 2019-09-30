// O(n^2)
// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "")
            return s;
        
        int size = s.size();
        int maxLen = 1;
        int start = 0;
        bool dp[size][size];

        memset(dp, false, sizeof(dp));

        for(int i = 0; i < size; i++) {
            dp[i][i] = true;
        }

        for(int i = 0; i < size-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }

        for(int k = 3; k <= size; k++) {
            for(int i = 0; i < size-k+1; i++) {
                int j = i + k - 1;

                if(dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if(k > maxLen) {
                        maxLen = k;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};