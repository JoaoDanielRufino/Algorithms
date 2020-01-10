// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> hash;
        vector<int> res;
        
        int count = 0;
        for(int i = 0; i < p.size(); i++) {
            hash[p[i]]++;
            hash[s[i]]--;
        }
        
        int l = 0;
        int r = p.size()-1;
        while(r < s.size()) {
            bool anagram = true;
            for(auto it : hash) {
                if(it.second) {
                    anagram = false;
                    break;
                }
            }
            
            if(anagram)
                res.push_back(l);
            
            hash[s[l]]++;
            l++;
            r++;
            if(r >= s.size())
                break;
            hash[s[r]]--;
        }
        
        return res;
    }
};