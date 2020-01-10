// https://leetcode.com/problems/replace-the-substring-for-balanced-string/

class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> hash;
        
        hash['Q'] = hash['E'] = hash['R'] = hash['W'] = -s.size()/4;
        
        for(char c : s)
            hash[c]++;
        
        if(!hash['Q'] && !hash['E'] && !hash['W'] && !hash['R'])
            return 0;
        
        int l, r, res = s.size();
        l = r = 0;
        while(r < s.size()) {
            while(r < s.size() && (hash['Q'] > 0 || hash['E'] > 0 || hash['W'] > 0 || hash['R'] > 0)) {
                hash[s[r]]--;
                r++;
            }
            
            while(l <= r && hash['Q'] <= 0 && hash['E'] <= 0 && hash['W'] <= 0 && hash['R'] <= 0) {
                hash[s[l]]++;
                l++;
            }
            
            res = min(res, r-l+1);
        }
        
        return res;
    }
};