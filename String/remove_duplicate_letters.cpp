// https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> hash(26, false);
        vector<bool> seen(26, false);
        string res;
        
        for(char c : s)
            hash[c - 'a']++;
        
        for(char c : s) {
            hash[c-'a']--;
            if(!seen[c-'a']) {
                while(!res.empty() && c < res.back() && hash[res.back()-'a']) {
                    seen[res.back()-'a'] = false;
                    res.pop_back();
                }
                res += c;
                seen[c-'a'] = true;
            }
        }
        
        return res;
    }
};