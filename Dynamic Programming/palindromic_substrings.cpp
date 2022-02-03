// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> isPalindrome(s.size()+1, vector<bool>(s.size()+1, false));
        int count = 0;

        for(int i = 0; i < s.size(); i++) {
            isPalindrome[i][i] = true;
            count++;
        }
        
        for(int l = 2; l <= s.size(); l++) {
            for(int i = 0; i <= s.size()-l; i++) {
                int j = i + l - 1;
                if(l == 2)
                    isPalindrome[i][j] = s[i] == s[j];
                else
                    isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i+1][j-1];
            
                count += isPalindrome[i][j];
            }
        }
        
        return count;
    }
};
