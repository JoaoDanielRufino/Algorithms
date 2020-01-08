// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int l, r, count, minLen = INT_MAX;
        string res;
        unordered_map<char, int> hash;
        
        for(char c : t)
            hash[c]++;
        
        l = r = 0;
        count = t.size();
        while(r < s.size()) {
            if(hash[s[r]] > 0)
                count--;
            hash[s[r]]--;
            while(!count) {
                if(minLen > r-l+1) {
                    minLen = r-l+1;
                    res = s.substr(l, minLen);
                }
                if(!hash[s[l]])
                    count++;
                hash[s[l]]++;
                l++;
            }
            r++;
        }
        
        return res;
    }
};