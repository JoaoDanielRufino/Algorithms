// https://leetcode.com/problems/letter-case-permutation/

class Solution {
public:
    vector<string> res;
    
    void solve(string s, int i) {
        if(i == s.size()) {
            res.push_back(s);
            return;
        }
        
        if(isdigit(s[i]))
            solve(s, i+1);
        else {
            s[i] = tolower(s[i]);
            solve(s, i+1);
            s[i] = toupper(s[i]);
            solve(s, i+1);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        solve(S, 0);
        
        return res;
    }
};