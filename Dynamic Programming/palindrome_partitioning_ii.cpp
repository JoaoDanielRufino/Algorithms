// https://leetcode.com/problems/palindrome-partitioning-ii/submissions/
// https://www.youtube.com/watch?v=WPr1jDh3bUQ

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<int> cut(n);
        
        for(int i = 0; i < n; i++)
            isPal[i][i] = true;
        
        for(int l = 2; l <= n; l++) {
            for(int i = 0; i <= n-l; i++) {
                int j = i + l - 1;
                if(l == 2)
                    isPal[i][j] = s[i] == s[j];
                else
                    isPal[i][j] = s[i] == s[j] && isPal[i+1][j-1];
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(isPal[0][i])
                cut[i] = 0;
            else {
                cut[i] = i;
                for(int j = 0; j < i; j++) {
                    if(isPal[j+1][i])
                        cut[i] = min(cut[i], 1 + cut[j]);
                }
            }
        }
        
        return cut[n-1];
    }
};