// https://leetcode.com/problems/longest-substring-without-repeating-characters/


// Sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> hash;
        int res = 0;
        int i, j;
        
        i = j = 0;
        while(j < s.size()) {
            if(!hash.count(s[j])) {
                hash.insert(s[j++]);
                res = max(res, j - i);
            }
            else
                hash.erase(s[i++]);
        }
        
        return res;
    }
};
